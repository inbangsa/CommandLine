#ifndef OPTIONS_H
#define OPTIONS_H
#include <iostream>
#include <string>


//This class stores the values of various command options 
namespace cmdParser
{
	//class Options stores the values of various command options.
	class Options
	{
	public:
	
		//options with parameters.
		Options(std::string short_command, std::string long_command, std::string short_description, std::string  long_description);

		//setters for setting values.
		void  set_option_short_command(std::string short_command);
		void  set_option_long_command(std::string long_command);
		
		//getters.
		std::string get_option_short_command()const;
		std::string get_option_long_command()const;
		std::string get_option_short_description()const;
		std::string get_option_long_description()const;

	private:
		//different parameters of the options. 
		std::string short_command, long_command, short_description, long_description;

	};
};
#endif OPTIONS_H
