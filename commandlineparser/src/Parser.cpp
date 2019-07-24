#include "Parser.h"

void cmdParser::Parser::AddOptions(std::string short_command, std::string long_command, std::string short_description, std::string long_description) 
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

void  cmdParser::Parser::tokenizer(int argc, char*argv[])
{
	// to store the stringstream ss till delimiter =
	std::string  intermediate;

	//for tokenizing the input string
	for (int i = 0; i < argc; i++)
	{
		std::stringstream ss(argv[i]);

		while (getline(ss, intermediate, '='))
		{
	   	 tokenized_data.push_back(intermediate);
		}
	}
}

bool cmdParser::Parser::Parse(int argc, char*argv[])
{
	tokenizer(argc,argv);
	return true;
}