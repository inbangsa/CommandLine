#include "Parser.h"

int  main(int argc, char*argv[])
{
	cmdParser::Parser obj;
	try
	{
		//Add the options.
		obj.AddOptions("cp", "copy", "short description ", "very very long description", std::string("hello world "));
		obj.AddOptions("", "port", "short description ", "very very long description",4528);

		// Type is bool implies flag.
		obj.AddOptions("f", "", "short description ", "very very long description", false);
	
		//Parse the command line arguments.
		obj.Parse(argc, argv);

		std::cout << "=========Using GetValue=======\n";
		//Retrieve the value for particular command.
		std::cout << "\n copy : "<<obj.GetValue<std::string>("copy");
		
		std::cout << "\n port : "<<obj.GetValue<int>("port");
		
		std::cout << "\n f : "<<obj.GetValue<bool>("f");
		std::cout << std::endl;
		
		std::cout <<"==========Using GetValues=======\n";
		
		//Retrieve the values for particular command.
		
		std::cout << "\n copy : ";
		auto val_copy=obj.GetValues<std::string>("copy");
		for (auto y : val_copy)
		{
			std::cout << y << " ";
		}

		auto val_port=obj.GetValues<int>("port");
		std::cout << "\n port : ";
		for (auto y : val_port)
		{
			std::cout << y<<" ";
		}

		std::cout << "\n f : ";
		auto val_flag = obj.GetValues<bool>("f");
		for (auto y :val_flag)
		{
			std::cout << y <<" ";
		}
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	return 0;
}
