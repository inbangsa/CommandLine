#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include<type_traits>

//This class stores the values of various command options 
namespace cmdParser
{
	//class Options stores the values of various command options.
	class Options
	{
	public:
		//options with parameters.

		Options(std::string short_command, std::string long_command, std::string short_description, std::string long_description)
			:long_description(long_description),short_description(short_description)
		{ 
			std::cout << "done:";
			set_option_short_command(short_command);
			set_option_long_command(long_command);
		}

		//setters for setting values.
		void set_option_short_command(std::string short_command);
		void set_option_long_command(std::string long_command);
		virtual void set_value(std::string&);

		//getters.
		std::string get_option_short_command()const;
		std::string get_option_long_command()const;
		std::string get_option_short_description()const;
		std::string get_option_long_description()const;

		//to empty the container containing the values for the command.
		virtual void clear_the_value();

	private:
		//different parameters of the options. 

		std::string short_command,long_command,short_description,long_description,default_value;

		//to store the value of command.
		std::vector<std::string>value;
	};

	template<typename T>
	class Options_with_value :public Options
	{
	public:
		Options_with_value(std::string short_command, std::string long_command, std::string short_description, std::string  long_description,T default_value) :
			Options(short_command, long_command, short_description, long_description)
		{
			set_value_t(default_value);
		}

		//setting up default value for the command.
		void set_value_t(T default_value)
		{	
			value.push_back(default_value);
		}

		//set the value for the command.
		void set_value(std::string &input)
		{
			std::istringstream ss(input);
			T num;
			ss >> num;
			value.push_back(num);
		}

		//to empty the container containing the values for the command.
		void clear_the_value()
		{
			value.clear();
		}

		//to get the value for the command.
		std::vector<T> get_value()const
		{
			return value;
		}

	private:
		//to store the value of command.
		std::vector<T> value;
	};
};
#endif OPTIONS_H
