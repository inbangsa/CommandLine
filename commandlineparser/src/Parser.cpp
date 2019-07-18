#include "Parser.h"

void cmdParser::Parser::add_options(std::string short_command, std::string long_command, std::string short_description, std::string long_description) 
{
	std::shared_ptr<cmdParser::Options> obj = std::make_shared<cmdParser::Options>(short_command, long_command, short_description, long_description);
	
	//if both  short and command a present make both  of them individually as key.

	if ((!(obj->get_option_short_command().empty())) && (!(obj->get_option_long_command().empty())))
	{
		command_list.insert(KeyValue(obj->get_option_short_command(), obj));
		command_list.insert(KeyValue(obj->get_option_long_command(), obj));
	}
	//if only  short command  is present ,make short command as key.
	else if (!(obj->get_option_short_command().empty()))
	{
		command_list.insert(KeyValue(obj->get_option_short_command(), obj));		
	}
	//if only long command is present, make long command as key.

	else if (!(obj->get_option_long_command().empty()))
	{
		command_list.insert(KeyValue(obj->get_option_long_command(), obj));
	}
	else
	{
		throw std::runtime_error("Enter a valid short or long command or both.");
	}
}


