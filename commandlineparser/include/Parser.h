#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <stdexcept>
#include "Options.h"

namespace cmdParser
{
	using CommandList = std::map<std::string, std::shared_ptr<cmdParser::Options>>;
	using KeyValue = std::pair<std::string, std::shared_ptr<cmdParser::Options>>;
	/*
	class Parser serves the following purpose:-
	[1]. Adds the user defined options.
	[2]. Parses the  input commandline data.
	[3]. Validates the commandline commands with the user defined commands.
	[4]. Gives the typecasted value corresponding to a particular command.
	[5]. Displays the default help.
	[6]. Generates the help whenever "-h" or "--help" command is found.
	*/
	class Parser
	{
	public:

		//adds the user defined options like ("", "port","port number","portnumber should be  of 4 digits only").
		void AddOptions(std::string short_command, std::string long_command, std::string short_description, std::string long_description);

		//parses_the_input data and gives key value pair in  string type.
		bool Parse(int argc, char*argv[]);

	private:

		//Tokenizes the argv with delimiter '=' , for <space> argv does automatically. 
		void tokenizer(int argc, char*argv[]);

		//a map for storing command Options.
		CommandList command_list;

		//storing the tokenized data.
		std::vector<std::string> tokenized_data;
	};
};
#endif PARSER_H

