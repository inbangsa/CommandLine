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

		auto x=obj.GetValue<std::string>("--copy");
		for (auto y : x)
		{
			std::cout << y;
		}
		
		auto z=obj.GetValue<int>("--port");
		for (auto y : z)
		{
				std::cout << y;
		}

=======
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
>>>>>>> [#24] implemented getValueAsString function to retrieve the value and made other changes as per as comments.
	}
	catch (std::exception &e)
	{
		std::cout << "[ Error ]:" << e.what();
	}
	return 0;
}
