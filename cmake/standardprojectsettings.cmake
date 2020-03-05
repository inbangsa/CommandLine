#This file is for setting the complier flags.

# setting few parameters
set(CMAKE_CXX_EXTENSIONS ON) 

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# setting of cmake_build_type doesnot works for MSVC from script file 
# can set config type during generate step of cmake using command [cmake --build . --config <BUILD_TYPE>] 
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)

	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type Release" FORCE)

endif()