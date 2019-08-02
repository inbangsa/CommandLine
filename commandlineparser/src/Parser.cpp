#include "Parser.h"

void cmdParser::Parser::add_options_object(std::shared_ptr<cmdParser::Options> obj)
{

	bool is_short_empty = false;

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

void  cmdParser::Parser::tokenizer(int argc, char* argv[])
{
	// to store the stringstream ss till delimiter =.
	std::string  intermediate;

	//for tokenizing the input string.
	for (int i = 0; i < argc; i++)
	{
		std::stringstream ss(argv[i]);

		while (getline(ss, intermediate, '='))
		{
	   	 tokenized_data.push_back(intermediate);
		}
	}
}

<
bool cmdParser::Parser::Parse(int argc, char* argv[])
{

	//begin of tokenizer.
	tokenizer(argc, argv);


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
			return true;
		}
		else
		{
			return false;
		}
	};

	call_help("-h", std::bind(&cmdParser::Parser::short_help, this, std::placeholders::_1));
	call_help("--help", std::bind(&cmdParser::Parser::long_help, this, std::placeholders::_1));

	
	extract_value_as_string(argc,argv);	

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


void cmdParser::Parser::extract_value_as_string(int argc, char**argv)
{
	//for identifying key from commandline and val is only for storing value  for the case --copy=45 =>here val=45.
	std::string key, val;

	for (int i = 1; i < argc; i++)
	{
		if (!(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) && (!(strcmp(argv[i - 1], "--help") == 0 || strcmp(argv[i - 1], "-h") == 0)))
		{
			//key finding  + validity checking + value next to delimiter"=" block. 
			if (argv[i][0] == '-' || argv[i][1] == '-')
			{
				std::string temp(argv[i]);

				//getting key and val for case example --copy=445 => key= --copy and val=445.
				size_t found = temp.find("=");
				if (found != std::string::npos)
				{
					key = temp.substr(0, found);
					val = temp.substr(temp.find("=") + 1);
				}
				//if  only key is there.Example  -cp 142 no '='.
				else
				{
					key = argv[i];
				}

				//validity check for the key. 
				if (command_list.find(key) == command_list.end())
				{
					throw std::exception(("Entered command [ " + key + " ] not found in the registered command list.").c_str());
				}

				//clear  older value for the command, example --copy=4 --copy=5 => 4 should be deleted.
				command_list[key]->clear_the_value();

				//store value for the case --copy=123 so key= --copy and val=123.
				if (!val.empty())
				{
					command_list[key]->set_value(val);
					val.clear();
				}
			}

			//for only data no key. --copy 152 123 25 store such values 152 123 25.
			else
			{
				command_list[key]->set_value(std::string(argv[i]));
			}
		}
	}
}
