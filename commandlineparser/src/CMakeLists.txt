#CMD_PARASER_LIB/SRC 
include_directories("${PROJECT_SOURCE_DIR}/commandlineparser/include")

add_library(mylib Options.cpp Parser.cpp  "../include/Parser.h" "../include/Options.h")
