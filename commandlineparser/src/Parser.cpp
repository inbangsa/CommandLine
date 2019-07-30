#include "Parser.h"

void cmdParser::Parser::AddOptions(std::string short_command,std::string long_command,std::string short_description,std::string long_description) 
{
	std::shared_ptr<cmdParser::Options> obj = std::make_shared<cmdParser::Options>(short_command,long_command,short_description,long_description);

	bool is_short_empty =false;

	if (!(obj->get_option_short_command().empty()))
	{
		command_list.insert(KeyValue(obj->get_option_short_command(),obj));
	}
	else
	{
		is_short_empty = true;
	}
	if (!(obj->get_option_long_command().empty()))
	{ 
		command_list.insert(KeyValue(obj->get_option_long_command(),obj));
	}
	else if (is_short_empty)
	{
		throw std::exception("Enter a valid short or long command or both.");
	}
}

void  cmdParser::Parser::tokenizer(int argc, char* argv[])
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

bool cmdParser::Parser::Parse(int argc,char* argv[])
{   
	//begin of tokenizer.
	tokenizer(argc,argv);
	
	std::vector<std::string> keys = help_qualifier_keys_finder();

	if (argc == 1)
	{
		default_help(keys);
	}

	// display short and long help.
	auto call_help = [&](std::string option, std::function<void(const std::vector<std::string>&)> help_function)
	{
		
		auto detect_help_option = std::find(tokenized_data.begin(), tokenized_data.end(), option);

		if (detect_help_option != tokenized_data.end())
		{
			help_function(keys);
		}
	};

	call_help("-h", std::bind(&cmdParser::Parser::short_help, this, std::placeholders::_1));
	call_help("--help", std::bind(&cmdParser::Parser::long_help, this, std::placeholders::_1));


	// display short and long help.
	auto detect_minus_minus_help = std::find(tokenized_data.begin(), tokenized_data.end(), "--help");

	if (detect_minus_minus_help != tokenized_data.end())
	{
		long_help(keys);
	}
	else
	{
		auto detect_minus_h = std::find(tokenized_data.begin(), tokenized_data.end(), "-h");
		if (detect_minus_h != tokenized_data.end())
		{
			short_help(keys);
		}
	}
	return true;
}

std::vector<std::string> cmdParser::Parser::help_qualifier_keys_finder()
{
	std::vector<std::string> help_keys;
	for (auto x : command_list)
	{
		if ((x.first.at(0) == '-') && (x.first.at(1) == '-'))
		{
			help_keys.push_back(x.first);
		}
		else if (x.second->get_option_long_command().empty())
		{
			help_keys.push_back(x.first);
		}
	}
	return help_keys;
}

void cmdParser::Parser::print(const std::vector<std::string>&keys, std::function<void(const std::string target_key)> print_help, std::string title)const
{
	std::cout << "\n **************WELCOME TO OPTIONS OF THE LIBRARY *********************" << std::endl;
	std::cout << "[FORMAT]" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Short_Command" << "\t" << "Long_Command" << "\t" << title << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	for_each(keys.begin(), keys.end(), print_help);
}

void cmdParser::Parser::default_help(const std::vector<std::string>& keys)const
{
	auto print_default_help = [&](const std::string target_key)
	{
		auto itr = command_list.at(target_key);

		std::cout<< "\n" <<itr->get_option_short_command()<< "\t\t" <<itr->get_option_long_command()<< "\t\t" << itr->get_option_short_description()<< "\t\t"<<itr->get_option_long_description()<<std::endl;
	};
	
 	print(keys, print_default_help, "Short_Description \t\t Long_Description");
}

void cmdParser::Parser::short_help(const std::vector<std::string>&keys)const
{
	auto print_short_help = [&](const std::string target_key)
	{
		auto itr = command_list.at(target_key);
		std::cout << "\n" << itr->get_option_short_command() << "\t\t" << itr->get_option_long_command() << "\t\t" << itr->get_option_short_description() << std::endl;
	};

	print(keys, print_short_help,"Short_Description");
}

void cmdParser::Parser::long_help(const std::vector<std::string>&keys) const
{
	auto print_long_help = [&](const std::string target_key)
	{
		auto itr = command_list.at(target_key);
		std::cout << "\n" << itr->get_option_short_command() << "\t\t" << itr->get_option_long_command() << "\t\t" << itr->get_option_long_description() << std::endl;
	};
	print(keys, print_long_help,"Long_Description");
}

