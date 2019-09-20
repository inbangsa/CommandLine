#include "Parser.h"

int  main(int argc, char*argv[])
{
	cmdParser::Parser obj;
	try
	{
		//Add the options.
		obj.AddOptions("cp", "copy", "short description ", "very very long description", std::string("hello world "));
		obj.AddOptions("", "port", "short description ", "very very long description",4528);

		// type is bool implies flag.
		obj.AddOptions("f", "", "short description ", "very very long description", false);
	
		//Parse the command line arguments.
		obj.Parse(argc, argv);


		//retrieve the value for particular command.
		std::cout << "\n copy : ";
		auto x=obj.GetValue<std::string>("copy");
		for (auto y : x)
		{
			std::cout << y;
		}

		auto z=obj.GetValue<int>("port");
		for (auto y : z)
		{
			std::cout << y;
		}

		std::cout << "\n f : ";
		auto k = obj.GetValue<bool>("f");
		for (auto y :k )
		{
			std::cout << y;
		}
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	return 0;
}
