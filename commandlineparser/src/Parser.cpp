#include "Parser.h"

void cmdParser::Parser::add_options(std::string short_command, std::string long_command, std::string short_description, std::string long_description) 
{
	std::shared_ptr<cmdParser::Options> obj = std::make_shared<cmdParser::Options>(short_command, long_command, short_description, long_description);

	bool is_short_empty =false;

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

