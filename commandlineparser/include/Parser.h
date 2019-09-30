#ifndef PARSER_H
#define PARSER_H

#include <algorithm>
#include <functional>
#include <sstream>
#include <map>
#include <stdexcept>
#include "Options.h"

namespace cmdParser
{	/** @defgroup groupA TypeAlias
    * TypeAlias 
    * @{
    */
	using CommandList = std::map<std::string, std::shared_ptr<cmdParser::Options>>;
	using KeyValue = std::pair<std::string, std::shared_ptr<cmdParser::Options>>;
	using StorgeType = std::map<std::string, std::vector<std::string>>;
	/** @} */ // end of group TypeAlias
	
	/**
	*  @brief Class Parser serves the following purpose:-<br>
	[1].Adds the user defined options.<br>
	[2].Parses the  input command line data.<br>
	[3].Validates the command line commands with the user defined commands.<br>
	[4].Gives the typecasted value corresponding to a particular command.<br>
	[5].Displays the default help.<br>
	[6].Generates help whenever "-h" or "--help" command is found .
	*/
	class Parser
	{
	public:
		/**
			* @brief Adds the user defined options like ("", "port","port number","portnumber should be  of 4 digits only").
			* @param short_command		Shorthand Command
			* @param long_command		Longhand Command
			* @param short_description  Short description of the command
			* @param long_description   Long description of the command
			* @param def_value			Default Value for the command.
			* @retval None		
		*/
		template<typename T>
		void AddOptions(std::string short_command,std::string long_command,std::string short_description,std::string long_description, T def_value);

		/**
			* @brief Parses the_input data and gives key-value pair in string type.
			* @param argc Command line argumemnt count
			* @param argv Command line data
			* @retval NONE
		*/
		bool Parse(int argc,char* argv[]);
		
		/**
			* @brief To get the value of the queried command in a desired fundemental data type.
			* @param input_command Queried command
			* @retval U
		*/
		template<typename U>
		U GetValue(const std::string& input_command);

		/** 
			* @brief To get the  values of the queried command as vector output.
			* @param input_command Queried command
			* @retval vector<U>
		*/
		template<typename U>
		std::vector<U>GetValues(const std::string& input_command);

	private:

		/**
			* @brief Tokenizes the argv with delimiter '=' , for <space> argv does automatically.
			* @param argc Command line Argumemnt count
			* @param argv Command line Data
			* @retval NONE
		*/
		void tokenizer(int argc,char *argv[]);

		/**
			* @brief To get the keys which will be used in the help option to retrive values from the command_list map.
		*/
		std::vector<std::string> help_qualifier_keys_finder();

		/**
			* @brief Default help option.
			* @param keys These are help keys -h , --help detected from the command line
			* @retval  None
		*/
		void default_help(const std::vector<std::string>& keys) const;

		/**
			* @brief Shows short description whenever -h occurs.
			* @param keys These are help keys -h , --help detected from the command line
			* @retval  None
		*/
		void short_help(const std::vector<std::string>&keys) const;

		/**
			* @brief Shows Long description whenever --help occurs.
			* @param keys  These are help keys -h , --help detected from the command line.
			* @retval None
		*/
		void long_help(const std::vector<std::string>&keys) const;

		/**
			* @brief To print the common portion in the help option and std::function to print various types of help.
			* @param keys These are help keys -h , ---help detected from the command line
			* @param print_help Lambda to print the speicific help functionality
			* @param title Title for a particular help say Long_Description
			* @retval None
		*/
		void print(const std::vector<std::string>&keys, std::function<void(const std::string target_key)> print_help, std::string title)const;

		/**
			* @brief To parser and store the corresponding value of input commands obtained by the commandline.
			* @param argc Command line argumemnt count
			* @param argv Command line data
			* @retval None
		*/
		void extract_value_as_string(int argc, char**argv);

		/**
			* @brief To process the addition of options to the commandlist  after object creation by AddObject function.
			* @param argc Pointer to the  object of class Option
			* @retval None
		*/
	    void add_options_object(std::shared_ptr<cmdParser::Options>);

		/**
			* @brief To make the command proper i.e. to append -- or - to the input command.
			* @param const std::string& 
			* @retval std::string
		*/
		std::string valid_command_maker(const std::string&);
		
		/**
			* @brief Fetch value for the command in vector form ,from  the Options class get value member function.
			* @param input_command queried command
			* @retval vector<U>
		*/
		template<typename U>
		std::vector<U> get_value_processing(const std::string & input);
		
		/**
			* @brief Storing the tokenized data.
		*/
		std::vector<std::string> tokenized_data;

		/**
			* @brief A map for storing command Options.
		*/
		CommandList command_list;
		
	};

	template <typename T>
	void cmdParser::Parser::AddOptions(std::string short_command, std::string long_command, std::string short_description, std::string long_description, T def_value)
	{
		static_assert(!std::is_convertible<T, const char *>::value, "const char * data type for string literal is not supported in this version !");
		std::shared_ptr<cmdParser::Options> obj = std::make_shared <cmdParser::Options_with_value<T>>(short_command, long_command, short_description, long_description, def_value);
		add_options_object(obj);
	}	

	template<typename U >
	std::vector <U> cmdParser::Parser::get_value_processing(const std::string& input)
	{
		std::string valid_query = valid_command_maker(input);
		auto call = [&](std::string query_input)
		{
			if (!query_input.empty())
			{
				auto temp = dynamic_cast<Options_with_value<U>*>(command_list.at(query_input).get());
				return  temp;
			}
		};
	
	    auto res = call(valid_query);
		
		if (res !=nullptr)
		{
			
			return res->get_value();
		}
		else
		{
			std::string err_msg = " Type mismatch for input argument : " + input + " of type " + typeid(U).name();
			throw std::exception(err_msg.c_str());
		}		
	}

	template<typename U>
	U cmdParser::Parser::GetValue(const std::string& input)
	{
		std::vector<U> temp_result = get_value_processing<U>(input);
		return temp_result[0];
	}

	template<typename U>
	std::vector<U> cmdParser::Parser::GetValues(const std::string& input)
	{
		return get_value_processing<U>(input);
	}
};
#endif PARSER_H

