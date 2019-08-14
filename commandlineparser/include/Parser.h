#ifndef PARSER_H
#define PARSER_H

#include <algorithm>
#include<functional>
#include <sstream>
#include <map>
#include <stdexcept>
#include "Options.h"

namespace cmdParser
{
	using CommandList = std::map<std::string, std::shared_ptr<cmdParser::Options>>;
	using KeyValue = std::pair<std::string, std::shared_ptr<cmdParser::Options>>;
	using StorgeType = std::map<std::string, std::vector<std::string>>;
	/*
	class Parser serves the following purpose:-
	[1]. Adds the user defined options.
	[2]. Parses the  input commandline data.
	[3]. Validates the commandline commands with the user defined commands.
	[4]. Gives the typecasted value corresponding to a particular command.
	[5]. Displays the default help.
	[6]. Generates the help whenever "-h" or "--help" command is found.
	*/
	class Parser
	{
	public:

		//adds the user defined options like ("", "port","port number","portnumber should be  of 4 digits only").
		template <typename T>
		void AddOptions(std::string short_command, std::string long_command, std::string short_description, std::string long_description, T def_value );

		//parses_the_input data and gives key value pair in  string type.
		bool Parse(int argc, char* argv[]);

		//to get the string type value of the queried command.
		template <typename T>
		std::vector<T> getValueAsString(const std::string &)const;
	//	std::vector<std::string> getValueAsString(const std::string &)const;

	private:
		//tokenizes the argv with delimiter '=' , for <space> argv does automatically. 
		void tokenizer(int argc, char *argv[]);

		//to get the keys which will be used in the help option to retrive values from the command_list map.
		std::vector<std::string> help_qualifier_keys_finder();

		//default help option.
		void default_help(const std::vector<std::string>& keys) const;

		//shows short description whenever -h occurs.
		void short_help(const std::vector<std::string>&keys) const;

		//shows long description whenever --help occurs.
		void long_help(const std::vector<std::string>&keys) const;

		//to print the common portion in the help option and std::function to print various types of help.
		void print(const std::vector<std::string>&keys, std::function<void(const std::string target_key)> print_help, std::string title)const;

		//to the store the corresponding value of input commands obtained by the commandline.
		void extract_value_as_string(int argc, char**argv);

		//a map for storing command Options.
		CommandList command_list;

		//storing the tokenized data.		
		std::vector<std::string> tokenized_data;
	};


	template <typename T>
	void cmdParser::Parser::AddOptions(std::string short_command, std::string long_command, std::string short_description, std::string long_description, T def_value)
	{
		std::shared_ptr<cmdParser::Options> obj = std::make_shared <cmdParser::Options_with_value<T>>(short_command, long_command, short_description, long_description, def_value);

		bool is_short_empty = false;

		if (!(obj->get_option_short_command().empty()))
		{
			command_list.insert(KeyValue(obj->get_option_short_command(), obj));
		}
		else
		{
			is_short_empty = true;
		}
		if (!(obj->get_option_long_command().empty()))
		{
			command_list.insert(KeyValue(obj->get_option_long_command(), obj));
		}
		else if (is_short_empty)
		{
			throw std::exception("Enter a valid short or long command or both.");
		}
 
	}

	template<typename T>
	std::vector <T> cmdParser::Parser::getValueAsString(const std::string &  input)const
	{
	 
			return dynamic_cast<Options_with_value<T>*>(command_list.at(input).get())->get_value();
	}



};
#endif PARSER_H

