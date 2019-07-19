#include "Parser.h"
int  main(int argc, char*argv[])
{
	cmdParser::Parser obj;
	try
	{
		obj.add_options("", "port", "short description ", "very very long description");
		obj.add_options("cp", "copy", "short description ", "very very long description");
		obj.add_options("IP", "", "short description ", "very very long description");
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	
return 0;
}
