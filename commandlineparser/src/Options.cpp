#include "Options.h" 

void cmdParser::Options::set_option_short_command(std::string short_command)
{
	if (!short_command.empty())
	{
		this->short_command = '-' + short_command;
	}
}

void cmdParser::Options::set_option_long_command(std::string long_command)
{
	if (!long_command.empty())
	{
		this->long_command = "--" + long_command;
	}
}

std::string cmdParser::Options::get_option_short_command()const
{
	return short_command;
}

std::string cmdParser::Options::get_option_long_command()const 
{
	return long_command;
}

std::string cmdParser::Options::get_option_short_description()const 
{
	return short_description; 
}

std::string cmdParser::Options::get_option_long_description()const 
{ 
	return long_description;
}

void cmdParser::Options::set_value(std::string &input)
{
}
 void cmdParser::Options::clear_the_value() 
{
}