#executable for the sample app
add_executable(SampleApp sample_user.cpp)

#linking library cmd_lib
target_link_libraries(SampleApp 
			PUBLIC cmd_lib
			PRIVATE project_warnings)

#install the targets 

install(TARGETS SampleApp DESTINATION ${_bin})
