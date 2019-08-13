#include "Options.h" 

cmdParser::Options::Options(std::string short_command, std::string long_command,
std::string short_description, std::string long_description, std::string default_Value)
 :long_description(long_description),short_description(short_description)
 {
	 set_option_short_command(short_command);
	 set_option_long_command(long_command);
 }

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

void cmdParser::Options::clear_the_value()
{
	value.clear();
}

std::vector<std::string> cmdParser::Options::get_value()const
{
	if (!value.empty())
	{
		return value;
	}
	else 
	{
		throw std::exception("The value is empty. ! ");
	}
}

void cmdParser::Options::set_value(const std::string &input)
{
	value.push_back(input);

}