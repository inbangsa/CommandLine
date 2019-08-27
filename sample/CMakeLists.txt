#include files 
include_directories(${PROJECT_SOURCE_DIR}/commandlineparser/include)

#executable for the sample app
add_executable(SampleApp sample_user.cpp)

#linking library cmd_lib
target_link_libraries(SampleApp cmd_lib)

#install the targets 
install(TARGETS SampleApp DESTINATION "${PROJECT_SOURCE_DIR}/install/bin")
