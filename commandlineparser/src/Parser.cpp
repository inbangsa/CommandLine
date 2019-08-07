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

	bool called_help_1=call_help("-h", std::bind(&cmdParser::Parser::short_help, this, std::placeholders::_1));
	bool called_help_2=call_help("--help", std::bind(&cmdParser::Parser::long_help, this, std::placeholders::_1));

	if (called_help_1 == 0 && called_help_2 == 0)
	{
		validity_checker(argc, argv);
		store_as_string(argc, argv);
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
		std::cout << "\n" << itr->get_option_short_command() << "\t\t" << itr->get_option_long_command() << "\t\t" << itr->get_option_short_description() << "\t\t" << itr->get_option_long_description() << std::endl;
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

void cmdParser::Parser::validity_checker(int argc, char *argv[])
{   //to store only commands extracted from command line for  the validity check with the registered options.
	std::map<std::string, int> store_commands;

	for (int i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-' || argv[i][1] == '-')
		{
				std::stringstream ss(argv[i]);
				std::string temp;
				getline(ss, temp, '=');

				if (command_list.find(temp) == command_list.end())
				{
					throw std::exception("Entered command not found in the registered command list");
				}
				//to conider only the last command for verification among all the same commands present in command line with registered options.		
				if (store_commands.find(temp) != store_commands.end())
				{
					store_commands.erase(temp);
					store_commands.insert({ temp, i });
				}
				else
				{
					store_commands.insert({ temp, i });
				}
		}
	}	
}

void cmdParser::Parser::store_as_string(int argc, char**argv)
{
	std::string key;
	for (int i = 1; i <argc; i++)
	{
		if (argv[i][0] == '-'|| argv[i][1] == '-')
		{
			std::string temp(argv[i]);
			size_t found = temp.find("=");
			if (found != std::string::npos)
			{
				key = temp.substr(0, temp.find("="));
				std::string val = temp.substr(temp.find("=") +1);
				
				//to remove the old value for already existing key.
				if (ValueAsString.find(key) != ValueAsString.end())
				{
					ValueAsString.erase(key);
				}
			
				//store for the case --copy=123 so key= --copy and val=123.
				ValueAsString[key].push_back(val);
			}
			//if  only key is there.Example  -cp 142 no '='.
			else 
			{ 
				key = argv[i];
			}	
		}
		//for only data no key. --copy 152 123 25 store such values 152 123 25.
		else 
		{	
			ValueAsString[key].push_back(argv[i]);
		}
		if (ValueAsString.find(key)== ValueAsString.end())
		{
			//std::cout << "key is here:" << key;
			ValueAsString[key].push_back("true");
		}
	}
}

std::vector <std::string> cmdParser::Parser::getValueAsString(const std::string &  input)
{
	if (ValueAsString.find(input) != ValueAsString.end())
	{
		return ValueAsString[input];
	}
	else 
	{
		throw std::exception("The value of quried command not found . ! ");
	}
}

