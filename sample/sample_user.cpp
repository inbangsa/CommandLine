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
		//example 1
		std::cout << "\n-----------------------\n";
		std::vector<std::string> val1=obj.ValueAsString["--port"];
		for (auto x : val1)
		{
			std::cout << "value :[--port]= "<<x<<std::endl;
		}
		//example 2
		std::cout << "\n-----------------------\n";
		std::vector<std::string> val2 = obj.ValueAsString["--copy"];
		for (auto x : val2)
		{
			std::cout <<"value : [--copy] "<< x << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	return 0;
}
