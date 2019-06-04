#include "cmd_line_parser.h"

cmd_parser::AddOptions::AddOptions()
{
}


cmd_parser::AddOptions::~AddOptions()
{
}

void  cmd_parser::ParseCmdLine::display_help(int argc, char *argv[])
{ 
if ((strcmp(argv[1],"--help")==0) || ((strcmp(argv[1],"-h")==0)))

{
	
		std::cout << "\n **************WELCOME TO OPTIONS OF THE LIBRARY *********************" << std::endl;
		std::cout << "[FORMAT]" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
		std::cout << "Short_Command" << "\t" << "Long_Command" << "\t " << "Short_Description" << " \t\t" << " Parameter_Type" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < so.size(); i++)
		{
			if (so[i] != "-") { std::cout << so[i]; };
		 if(lo[i]!=" ")std::cout<< "\t\t" << lo[i] ;
		 if(s_desc[i]!=" ")std::cout<< "\t\t " << s_desc[i]  ;
		 std::cout<< " \t\t "<<data[i] << std::endl<<std::endl;
		}

	}
}


void  cmd_parser::ParseCmdLine::string_parser(int argc, char*argv[])
{
if ((strcmp(argv[1],"--help")!=0)&&(strcmp(argv[1],"-h")!=0) )

{
	std::vector<std::string> parsed_raw_data;
	
	for (int i = 0; i < argc; ++i)
	{
		
		std::string temp;
		temp = (std::string)argv[i];
		
		
		if(temp.find("=")!=0)
		{
			std::string s = temp;
			std::string delimiter = "=";

			size_t pos = 0;
			std::string token;
			while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			s.erase(0, pos + delimiter.length());
			parsed_raw_data.push_back(token);
			
		}
			
			parsed_raw_data.push_back(s);
		}
		else 
		{ 
			parsed_raw_data.push_back(argv[i]);
		
		}
	}
	//uncomment the next line if one want's the parsed_raW_data
	//for (auto & x : parsed_raw_data) { std::cout << x << std::endl;  }

	//making the map of the parsed_command_and_respective_value
	std::map<std::string, std::string> parsed_command_value;
	for (int i = 1; i <parsed_raw_data.size(); i=i+2) {
		parsed_command_value.insert(std::pair<std::string,std::string>(parsed_raw_data[i], parsed_raw_data[i+1]));
	 }
	//uncomment if someone wants to see the map of the parsed_command_and_respective_value
	//for (auto x : parsed_command_value) { std::cout << x.first << "\t" << x.second<<std::endl; }
}

}