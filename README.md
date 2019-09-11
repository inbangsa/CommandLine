# CommandLineParser
# Introduction
[1].CommandLineParser library adds the user defined command line options which accepts the short command,long command,short description,long description and a default value.

[2].This library parses the command line options and gives the corresponding value of a particular command.

[3].The CommandLine Parser Library supports custom help functionality.

[4].The command line Options can be of the following forms :- 

    --port=3132
    --port 3132
    -p
    -cp
    -p 4215
    
[5].Example 

Register a command say port 
 
    obj.AddOptions("p", "port", "enter the port numbers", "port number must be of 4 digits",1234);
 
In  CommandPrompt

    SampleApp.exe --port=3241 4258
 
 Result 
    
    The value for --port : 324 425

# Usage
[1]. Include the library header file. 

    #include "Parser.h"   
[2]. Make an object of the class cmdParser::Parser.
 
    cmdParser::Parser obj;
[3]. Register the options.
	
	Syntax:-
	AddOptions(std::string short_command, std::string long command,std::String short description, std::string long description, T default_value);
    
    Example:-
    obj.AddOptions("cp", "copy", "copies files ", "copies contents of file 1 to file 2. ", std::string("abc.txt"));
	obj.AddOptions("", "port", "port number ", "enter four digits port number.",4528);
	
[4]. Parse the command line input.
   
    Syntax:-
    Parse(int argc, char**argv);
    
    Example:-
    obj.Parse(argc, argv);

[5]. Get the return value for a command.
  
    Syntax:-
    std::vector<T>GetValue(const std:string &);
  
    Example:-
    auto val_=obj.GetValue<int>("port");

# Installation
## For Windows 
## Part-A Requirements
[1]. CMake v3.9.1
[2]. Visual Studio Community 2017 or any previous version
[3]. Git for Windows or any git client (Optional)
## Part-B Building cmd_lib

 [1]. Setting  some of the required varibles.

 a) Setting a Directory for building the library.
            
    set cmd_lib_BUILD_DIR=C:\commandlineparser

b) Setting the Configuration of the build
    
    set CONFIG=Release

[2]. Creating directory for building the libraray.

     mkdir %cmd_lib_BUILD_DIR%

[2]. Clone the repository
	 
	 cd  %cmd_lib_BUILD_DIR%
	 git clone  https://github.com/inbangsa/CommandLine.git
 
[3]. Build the Library  

     cmake -Ax64 -DCMAKE_INSTALL_PREFIX="%cmd_lib_BUILD_DIR%\install" -L ..
	 cmake --build . --clean-first --config %CONFIG% --target install   
[3]. For using in other projects/library.

     cmake -Ax64 -DCMAKE_INSTALL_PREFIX="%cmd_lib_BUILD_DIR%\install" -L ..
	 cmake --build . --clean-first --config %CONFIG% --target install  
This library has cmake build system which supports the find_package() functionlaity .

#  Help Feature
This library has three help menus which are described below:-

 [1] Default Help :- shows the complete help menu which incorporates short command, long command , short description and long decription .This can be invoked by using <executable_name>.<extension_name>  
 
 Example  SampleApp.exe
 
[2]. Short Help :- Shows the help menu with short command, long command and short description. This can be invoked by -h flag.

[3].Long Help :- Shows the help menu with short command, long command and long description . This can be invoked by --help flag 

# Exceptions
 [1]. This library doesnot support the default value of type const char *. User may convert it to std::string .

 [2]. Any usage of unregistered command options results in error.

 [3].Explicit instantiation of GetValue() function is a must.

 [4]. All the exceptions gives error defined using what, which can be printed to see the error. 

# TODO
[1]. Passing initializer list or vector as default value.
[2]. Support cons char * as data type for user defined options.
[3]. GTest (Unit Testing)