#include<vector>
#include<string> 
#include<iostream>


namespace cmd_parser
{
	
	class AddOptions
	{
	protected:
		std::vector<std::string> so;//short command  of the option 
		std::vector<std::string> lo;//long command  of the option 
		std::vector<std::string> s_desc;//short description of the  option 
		std::vector<std::string> l_desc;//long description of the option
		std::vector<std::string> data; //storing the data type of the value accepted by the command 
	public:
		AddOptions();
		~AddOptions();
		template <typename T>
		void add_options(std::string short_option, std::string long_option, std::string short_description, std::string long_descriptionl,T val);//add_options 
	};
	
	
	class ParseCmdLine :public AddOptions
	{
	public:
	void display_help(int argc, char *argv[]);//display_help() shows the information about the options

	

	};


}

//definition of the "add_options()" as template function definition must be in .h file. 
	
	template <class T>
	void cmd_parser::AddOptions::add_options(std::string short_option, std::string long_option, std::string short_description, std::string long_description, T val)
	{
		so.push_back('-'+short_option);
		lo.push_back("--"+long_option);
		s_desc.push_back(short_description);
		l_desc.push_back(long_description);
		data.push_back(static_cast<std::string>(typeid(val).name()));

	}
	