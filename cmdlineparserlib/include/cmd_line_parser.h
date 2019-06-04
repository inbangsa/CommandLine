#include<map>
#include<unordered_map>
#include<vector>
#include<string> 
#include<iostream>
#include<algorithm>
#include <cstdio>

namespace cmd_parser
{
	
	class AddOptions
	{
	protected:

		std::vector<std::string> so;//for  short command 
		std::vector<std::string> lo;//for long command
		std::vector<std::string> s_desc;//for short description
		std::vector<std::string> l_desc;//for long description
		std::vector<std::string> data; //for data type of command 
	public:


		AddOptions();
		~AddOptions();
		template <typename T>
		void add_options(std::string short_option, std::string long_option, std::string short_description, std::string long_descriptionl,T val);
	};
	//definition  of add_options()
	template <class T>
	void cmd_parser::AddOptions::add_options(std::string short_option, std::string long_option, std::string short_description, std::string long_description, T val)
	{
		so.push_back('-'+short_option);
		lo.push_back("--"+long_option);
		s_desc.push_back(short_description);
		l_desc.push_back(long_description);
		data.push_back(static_cast<std::string>(typeid(val).name()));

	}
	class ParseCmdLine :public AddOptions
	{
	public:
	void display_help(int argc, char *argv[]);//default options for help 
	void cmd_parser::ParseCmdLine::string_parser(int argc, char*argv[]);//parses the command line arguments

	};

}