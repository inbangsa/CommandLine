#include "Parser.h"
int  main(int argc, char*argv[])
{
	cmdParser::Parser obj;
	try
	{
		obj.AddOptions("", "port", "short description ", "very very long description");
		obj.AddOptions("cp", "copy", "short description ", "very very long description");
		obj.AddOptions("IP", "", "short description ", "very very long description");
		obj.Parse(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	
return 0;
}
