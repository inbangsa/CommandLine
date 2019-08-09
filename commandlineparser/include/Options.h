#ifndef OPTIONS_H
#define OPTIONS_H


#include <iostream>
#include <string>
#include <vector>

//This class stores the values of various command options 
namespace cmdParser
{
	//class Options stores the values of various command options.
	class Options
	{
	public:
		//options with parameters.
		Options(std::string short_command, std::string long_command, std::string short_description, std::string  long_description, std::string default_Value = "true");

		//setters for setting values.
		void set_option_short_command(std::string short_command);
		void set_option_long_command(std::string long_command);
		void set_value(const std::string&);

		//getters.
		std::string get_option_short_command()const;
		std::string get_option_long_command()const;
		std::string get_option_short_description()const;
		std::string get_option_long_description()const;

		//to the value for the command.
		std::vector<std::string> get_value()const;

		//to empty the container containing the values for the command.
		void clear_the_value();

	private:
		//different parameters of the options. 
		std::string short_command,long_command,short_description,long_description,default_value;

		//to store the value of command.
		std::vector<std::string>value;
	};
};
#endif OPTIONS_H
