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
		//example1
		auto val1=obj.getValueAsString("--port");
		for (auto x : val1)
		{
			std::cout <<" "<< x << " ";
		}
		//example 2
		auto val2 = obj.getValueAsString("--copy");
		for (auto x : val2)
		{
			std::cout << " " << x << " ";
		}
		//example 3
		auto val3 = obj.getValueAsString("--cow");
		for (auto x : val3)
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
