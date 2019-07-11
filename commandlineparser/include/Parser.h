#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>

#include "Options.h"

#ifndef PARSER_H
#define PARSER_H

namespace cmdParser
{
	class Parser 
	{
		std::map<std::string ,opts::Options*> command_list; 
		public:
		void add_options(std::string short_command ,std::string long_command,std::string short_description, std::string long_description);
		
    };
};
#endif PARSER_H

