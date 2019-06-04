#include"cmd_line_parser.h"
#include<iostream> 
#include<vector>
#include<string>
#include<algorithm>

int main(int argc, char *argv[])
{
	//cmd_parser::Add_Options opt;
	cmd_parser::ParseCmdLine opt;


	//Instructions opt.add_options(so, lo, .., <sample input>)
	opt.add_options("cp", "copy", "copies_the_string", " Base class for all option that have a fixed type \n and are willing to announce this type to the outside world.\n Any 'value_semantics' forwhich you want to find out the type can be dynamic_cast - ed to typed_value_base.\n If conversion succeeds, the 'type'method can be called.typed_value ",10000);
	opt.add_options("cp1", "copy1", "copies_the_string1", "do this way1 ", "Sachin");
	opt.add_options("mv", "move", "moves_the_string1", " this is the", " ");
	opt.add_options("Ip", "Ip", "takes ip address", "example 192.152.125", "182.253.25");
	opt.add_options("", "port", "enter port number", "only part , it should be 4 letter only", "1253");
	opt.display_help(argc, argv);
	opt.string_parser(argc, argv);

	
	return 0;
	
	
	
	
	
	
	
}
