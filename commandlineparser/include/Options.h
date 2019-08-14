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
		
		Options(std::string short_command, std::string long_command, std::string short_description, std::string  long_description) 
			:long_description(long_description), short_description(short_description)
		{
			set_option_short_command(short_command);
			set_option_long_command(long_command);
		}

		//setters for setting values.
		void set_option_short_command(std::string short_command);
		void set_option_long_command(std::string long_command);
		virtual void set_value(const std::string& input)=0;

		//getters.
		std::string get_option_short_command()const;
		std::string get_option_long_command()const;
		std::string get_option_short_description()const;
		std::string get_option_long_description()const;

		//to empty the container containing the va.lues for the command.
		virtual void clear_the_value()=0;

	private:
		//different parameters of the options. 
		std::string short_command,long_command,short_description,long_description,default_value;
		
	};

template <typename T>
class Options_with_value :public Options
{
public:
	template <typename T>
	Options_with_value(std::string short_command, std::string long_command, std::string short_description, std::string  long_description, T default_value) :
		Options(short_command, long_command, short_description, long_description)
	{
		set_value(default_value);
	}

	void set_value(const std::string& input)
	{
		std::istringstream ss(input);
		T num;
		ss >> num;
		
		value.push_back(num);
	}
	void set_value(const T& input)
	{
		value.push_back(input);
	}

	std::vector<T> get_value()const
	{
		return val;
	}

	void clear_the_value()
	{
		value.clear();
	}

#if 0
	std::vector<T> get_value()const
	{
		return value;
	}
#endif
	std::vector<std::string> get_value()const
	{
		std::vector<std::string> str;
		//convert T to str .
		return str;
	}

private:
	std::vector<T> value; 
};

};
#endif OPTIONS_H
