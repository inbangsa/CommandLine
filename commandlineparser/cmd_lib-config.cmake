#get_filename_component(SELF_DIR ${CMAKE_CURRENT_LIST_FILE} PATH)
#message("**************"${SELF_DIR})
#include(${SELF_DIR}/cmd_lib.cmake)
 
 get_filename_component(cmd_lib_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
 #message("**************"${cmd_lib_DIR})
set(cms_lib_INCLUDE_DIRS include)
#message(STATUS "RapidJSON found. Headers: ${RAPIDJSON_INCLUDE_DIRS}")
