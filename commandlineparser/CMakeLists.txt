# setting relative paths for the install the directory
set(include_dest include)
set(lib_dest lib/${DBUILD_TYPE})


#add the library
add_library(cmd_lib src/Options.cpp src/Parser.cpp include/Parser.h include/Options.h)

#include lib needed by the library
target_include_directories(
							cmd_lib PUBLIC
							$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 		 
							$<INSTALL_INTERFACE:${include_dest}> 
							$<INSTALL_INTERFACE:${lib_dest}> 
						)
					   
#export the target of the library
install(TARGETS cmd_lib  EXPORT cmd_lib DESTINATION ${lib_dest})

#install the include files
install(FILES include/Parser.h  DESTINATION ${include_dest})
install(FILES include/Options.h DESTINATION ${include_dest})

#install the export group
install(EXPORT cmd_lib DESTINATION ${lib_dest})

#install the <target_name>-config.cmake file 
install(FILES cmd_lib-config.cmake DESTINATION ${lib_dest})


