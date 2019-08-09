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
		obj.AddOptions("f", "", "force operation ", "e.g. git checkout -f feature/branch_name");

		obj.Parse(argc, argv);

		//example 1 for querying value for  the command.
		auto val1=obj.getValueAsString("--port");
		std::cout << "\n --port : ";
		for (auto x : val1)
		{
			std::cout <<" "<< x << " ";
		}
		//example 2 for querying value for  the command.
		auto val2 = obj.getValueAsString("--copy");
		std::cout << "\n --copy : ";
		for (auto x : val2)
		{
			std::cout << " " << x << " ";
		}
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	return 0;
}
