cmake_minimum_required(VERSION 3.4)
project(command_line_parser)

#set complier varibles/specifications
include(cmake/standardprojectsettings.cmake)

#This lib has  no location and has to be linked for the enforcing complier warnings
add_library(project_warnings INTERFACE)

#complier warnings management.
include(cmake/compilerwarnings.cmake)
set_project_warnings(project_warnings)


#static analysis of code
include(cmake/staticanalyzer.cmake)


# setting relative paths for the install the directory
set(_include include)
set(_lib lib/${CMAKE_BUILD_TYPE})
set(_bin bin/${CMAKE_BUILD_TYPE})

#adding the directory of sample application and library  
add_subdirectory(commandlineparser)
add_subdirectory(sample)



# to generate doxygen documents
include(cmake/doxygen.cmake)
enable_doxygen()

