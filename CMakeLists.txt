cmake_minimum_required(VERSION 3.4)
project(command_line_parser)

# global compiler flags
set(CMAKE_BUILD_TYPE Release) # Release or Debug
set(CMAKE_CXX_EXTENSIONS OFF) # OFF -> -std=c++14, ON -> -std=gnu++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(WIN32)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else(WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-literal-suffix -s")
endif(WIN32)

# setting relative paths for the install the directory
set(_include include)
set(_lib lib)
set(_bin bin)


#adding the directory of sample application and library  
add_subdirectory(sample)
add_subdirectory(commandlineparser)
