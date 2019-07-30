#include "Parser.h"
int  main(int argc, char*argv[])
{
	cmdParser::Parser obj;
	try
	{
		obj.AddOptions("cp", "copy", "short description ", "very very long description");
		obj.AddOptions("mv", "move", "short description ", "very very long description");
		obj.AddOptions("", "port", "short description ", "very very long description");
		obj.AddOptions("", "find", "short description ", "very very long description");
		obj.AddOptions("D", "", "short description ", "very very long description");
		obj.AddOptions("IP", "", "short description ", "very very long description");
		obj.Parse(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	return 0;
}
