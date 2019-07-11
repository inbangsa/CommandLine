#include "Parser.h"

void cmdParser::Parser::add_options(std::string short_command ,std::string long_command,std::string short_description, std::string long_description)
{	
	opts::Options *obj=new opts::Options(short_command,long_command,short_description,long_description);
	
	if(!(obj->get_option_short_command().empty()))
	{	
		command_list.insert(std::pair<std::string,opts::Options*>(obj->get_option_short_command(),obj));
	}	
	else if(!(obj->get_option_long_command().empty()))
	{
		command_list.insert(std::pair<std::string,opts::Options*>(obj->get_option_long_command(),obj));
		
	}
	else
	{
		std::cout<<"Enter a valid short or long command or both";
	}
}
