#include "Parser.h"

int  main(int argc, char*argv[])
{
	cmdParser::Parser obj;
	try
	{
		obj.AddOptions("cp", "copy", "short description ", "very very long description", std::string("hello"));
		obj.AddOptions("", "port", "short description ", "very very long description",4528);
	    
		obj.Parse(argc, argv);

<<<<<<< HEAD
		auto x=obj.GetValue<std::string>("copy");
=======

		auto x=obj.GetValue<std::string>("--copy");
>>>>>>> [25]added GetValue function .
		for (auto y : x)
		{
			std::cout << y;
		}
 
		auto z=obj.GetValue<int>("port");
		for (auto y : z)
		{
				std::cout << y;

		}
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	return 0;
}
