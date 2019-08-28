#make a list of all header files
file(GLOB header_files ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

#make a list of all the source files 
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#add the library
add_library(cmd_lib ${header_files} ${src_files})

#include paths needed by the library to access the include files
target_include_directories(
							cmd_lib PUBLIC
							$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 		 
							$<INSTALL_INTERFACE:${_include}> 
							$<INSTALL_INTERFACE:${_lib}> 
						)
					   
#export the target of the library
install(TARGETS cmd_lib 
EXPORT cmd_lib 
RUNTIME       DESTINATION ${_bin}
LIBRARY       DESTINATION ${_lib}
ARCHIVE       DESTINATION ${_lib}
PUBLIC_HEADER DESTINATION ${_include}
)

#install the include files
install(FILES ${header_files} DESTINATION ${_include})

#install the export group
install(EXPORT cmd_lib DESTINATION ${_lib})

#install the <target_name>-config.cmake file 
install(FILES cmd_lib-config.cmake DESTINATION ${_lib})
#install(FILES cmd_lib-config.cmake DESTINATION "${_lib}/..")
