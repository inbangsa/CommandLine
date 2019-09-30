#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
/**
	* @brief Namespace of the lib ->cmdParser.
*/
namespace cmdParser
{
	/**
		* @brief The class Options stores the values of various command options.
	*/
	class Options
	{
	public:
		/**
			* @brief Options Constructor with parameters.<br>
			* @param short_command     Parameter for short command<br>
			* @param long_command      Parameter for long command <br>
			* @param short_description Description for short_command<br>
			* @param long_description  Description for long_command<br>
			* @retval None
		*/
		Options(std::string short_command, std::string long_command, std::string short_description, std::string long_description)
			:long_description(long_description),short_description(short_description)
		{ 
			set_option_short_command(short_command);
			set_option_long_command(long_command);
		}

		/** @defgroup group1 Setters
			* Setters
			* @{
		*/
		
		/**
			* @brief Sets the Short Command.
			* @param short_command For setting input value from AddOptions corresponding to short_command
			* @retval None
		*/		
		void set_option_short_command(std::string short_command);
		
		/**
			* @brief  Sets the Long Command.
			* @param long_command For setting input value from AddOptions corresponding to long_command
			* @retval None
		*/
		void set_option_long_command(std::string long_command);

		/**
			* @brief Sets the parsed value to the corresponding Command/Option.
			* @param std::string
			* @retval None
		*/
		virtual void set_value(std::string&);
		/** @} */ // end of group1 getters

		/** @defgroup group2  Getters
			*  Getters
			*  @{
		*/

		/**
			* @brief Get the value corresponding to Short Command.
			* @retval std::string
		*/
		std::string get_option_short_command()const;

		/**
			* @brief Get the value corresponding to  Long Command.
			* @retval std::string
		*/
		std::string get_option_long_command()const;

		/**
			* @brief  Get the value corresponding to Short Description.
			* @retval std::string
		*/
		std::string get_option_short_description()const;

		/**
			* @brief  Get the value corresponding to Long Description.
			* @retval std::string
		*/
		std::string get_option_long_description()const;
		/** @} */ // end of group2 getters
		
		/**
			* @brief To empty the container containing the values for the command.
			* @retval None
		*/		
		virtual void clear_the_value();


		/**
			* @brief To check the type of T bool or not.
			* @retval None
		*/
		virtual bool check_type_is_bool();
	private:
		/**
			* @brief  Different parameters of the options.
		*/
		std::string short_command,long_command,short_description,long_description,default_value;

		/**
			* @brief  To store the value of command.
		*/
		std::vector<std::string>value;
	};


	/**
		* @brief This class stores the values of various command options along with default value.
	*/
	template<typename T>
	class Options_with_value :public Options
	{
	public:
		Options_with_value(std::string short_command, std::string long_command, std::string short_description, std::string  long_description,T default_value) :
			Options(short_command, long_command, short_description, long_description)
		{
			set_value_t(default_value);
		}


		/**
			* @brief Setting up default value for the command.
			* @param default_value default value of the command
			* @retval None
		*/
		void set_value_t(T default_value)
		{	
			value.push_back(default_value);
		}

		/**
			* @brief Set the value for the command.
			* @param input Value to be set
			* @retval None
		*/
		void set_value(std::string &input)
		{
			std::istringstream ss(input);
			T num;
			ss >> num;
			value.push_back((T)num);
		}

		/**
			* @brief To empty the container containing the values for the command.
			* @retval None
		*/
		void clear_the_value()
		{
			value.clear();
		}

		/**
			* @brief to get the value for the command.
			* @retval std::vector<T>
		*/
		std::vector<T> get_value()const
		{
			return value;
		}

		/**
			* @brief To check the type of T is bool or not ,if bool => flag, else not a flag . 
			* @retval std::vector<T>
		*/
		bool check_type_is_bool()
		{
			T num;
			if (typeid(num).name() == typeid(bool).name())
				return true;
			else 
				return false;
		}
	
	private:
		/**
			* @brief To store the value of command.
			* @retval None
		*/
		std::vector<T> value;
	};

};
#endif OPTIONS_H
