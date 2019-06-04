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
