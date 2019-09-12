# CommandLineParser
# Introduction
- CommandLineParser library adds the user defined command line options which accepts the short command,long command,short description,long description and a default value.

- This library parses the command line options and gives the corresponding value of a particular command.

- The CommandLine Parser Library supports custom help functionality.

- The command line Options can be of the following forms :- 
    ```cpp
    --long_command=value
    --long_command value
    -short_command=value
    -short_command value
    -short_command (flag)
    --long_command (flag)
    ```
# Example
- #### Register a command say port.
    ```cpp
    obj.Addoptions("p", "port", "enter the port numbers", "port number must be of 4 digits",1234);
     ```
- #### In CommandPrompt.
    ```cpp
    SampleApp.exe --port=3241 4258
    ```` 
- #### Result.
   ```cpp 
    The value for port : 3248 4244
    ```
# Usage
- #### Include the library header file. 
  ```cpp
    #include "Parser.h"   
  ```
-  #### Make an object of the class cmdParser::Parser.
     ```cpp
       cmdParser::Parser obj;
    ```
-  #### Register the options.
	**Syntax:-** 
    ```cpp
	AddOptions(std::string short_command, std::string long command,std::String short description, std::string long description, T default_value);
    ```
    **Example:-**
    ```cpp
    obj.AddOptions("cp", "copy", "copies files ", "copies contents of file 1 to file 2. ", std::string("abc.txt"));
	obj.AddOptions("", "port", "port number ", "enter four digits port number.",4528);
   ```
- ####  Parse the command line input.
   
    **Syntax:-**
    ```cpp
    Parse(int argc, char**argv);
    ```    
    **Example:-**
    ```cpp
    obj.Parse(argc, argv);
    ```
- #### Get the return value for a command.
    **Syntax:-**
    ```cpp
    std::vector<T>GetValue(const std:string &);
    ```  
    **Example:-**
    ```cpp
    auto val_=obj.GetValue<int>("port");
    ```  
# Installation
###  For Windows 
###  Part-A Requirements
- CMake v3.9.1
- Visual Studio Community 2017 or any previous version.
- Git for Windows or any git client (Optional).
### Part-B Building cmd_lib

### [1]. Setting  some of the required varibles.

 - #### Set a directory for building the library.
    ```cmake        
    set cmd_lib_BUILD_DIR=C:\commandlineparser
    ```
- #### Set the configuration of the build.
    ```cmake
    set CONFIG=Release
    ```
### [2]. Download library in the build directory.
- ####  Create a build directory.
    ``` cmake 
    mkdir %cmd_lib_BUILD_DIR%
    ```
- ####  Clone the repository.
    ``` cmake 
	cd  %cmd_lib_BUILD_DIR%
	git clone  https://github.com/inbangsa/CommandLine.git
    ```
### [3]. Build Library. 
```cmake
cmake -Ax64 -DCMAKE_INSTALL_PREFIX="%cmd_lib_BUILD_DIR%\install" -L ..
cmake --build . --clean-first --config %CONFIG% --target install   
```
### [4]. For using in other projects/library.
```cmake
cmake -Ax64 -DCMAKE_INSTALL_PREFIX="%cmd_lib_BUILD_DIR%\install" -L ..
cmake --build . --clean-first --config %CONFIG% --target install  
```
This library has cmake build system which supports the find_package() functionality .

#  Help Feature
This library has three help menus which are described below:-
- **Default Help:-** shows the complete help menu which incorporates short command, long command , short description and long decription .This can be invoked by using <executable_name>.<extension_name> . (*Example:-*  SampleApp.exe) 

- **Short Help:-**  Shows the help menu with short command, long command and short description. This can be invoked by -h flag.

- **Long Help:-**  Shows the help menu with short command, long command and long description . This can be invoked by --help flag .

# Exceptions
- This library doesnot support the default value of type const char *. User may convert it to std::string .

- Any usage of unregistered command options results in error.

- Explicit instantiation of GetValue<type>() function is a must.

- All the exceptions gives error defined using what, which can be printed to see the error. 

# TODO
- Passing initializer list or vector as default value.

- Support const char * as data type for user defined options.

- GTest (Unit Testing)