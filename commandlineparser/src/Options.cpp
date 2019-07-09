#include"Options.h" 

Options::Options(std::string short_command, std::string long_command,
std::string short_description, std::string long_description)
 :long_description(long_description),short_description(short_description)
 {
	 set_option_short_command(short_command);
	 set_option_long_command(long_command);
 }
 
 Options::Options(std::string long_command):short_description(""),short_command(""),long_description("")
 {  set_option_long_command(long_command);
 
 }
 
void Options::set_option_short_command(std::string short_command){if(!short_command.empty()){this->short_command='-'+short_command;}}
void Options::set_option_long_command(std::string long_command){if(!long_command.empty()){this->long_command="--"+long_command;}}



std::string Options::get_option_short_command()const { return short_command; }
std::string Options::get_option_long_command()const { return long_command; }
std::string Options::get_option_short_description()const { return short_description; }
std::string Options::get_option_long_description()const { return long_description; }

