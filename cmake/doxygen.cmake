#doxygen file.
# this is doxygen based .chm document file generation script.
# this is based on cmake support for doxygen.
#

function(enable_doxygen)
  option(ENABLE_DOXYGEN "Enable doxygen doc builds of source" ON)
  if(ENABLE_DOXYGEN)
  
	find_package(Doxygen)
		if(DOXYGEN_FOUND)
			

			#setting required varibles for the doxygen file generation before the doxygen_add_docs command.
			file(MAKE_DIRECTORY docs/doxygendocuments)
			set(DOXYGEN_EXTRACT_ALL NO)
			set(DOXYGEN_PROJECT_NAME ${PROJECT_NAME})
 			set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/docs/doxygendocuments)
 			set(DOXYGEN_PROJECT_BRIEF "Command Line Parser is a C++ based project for parsing the command line arguments and retrieve the values corresponding to a particular command.")
			set(DOXYGEN_GENERATE_HTML YES)
			set(DOXYGEN_GENERATE_HTMLHELP YES)
			set(DOXYGEN_CHM_FILE cmd_lib.chm)
			set(DOXYGEN_SEARCHENGINE NO)
			set(DOXYGEN_HHC_LOCATION  "C:/Program Files (x86)/HTML Help Workshop/hhc.exe")
			set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${PROJECT_SOURCE_DIR}/README.md)

			#doxygen_add_docs creates a custom target doxygen-docs .
			doxygen_add_docs(run_doxygen ${PROJECT_SOURCE_DIR}/commandlineparser/include ${PROJECT_SOURCE_DIR}/README.md
			WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doxygen
			)     
			
			#install doxygen files
			INSTALL(FILES ${PROJECT_SOURCE_DIR}/docs/doxygendocuments/html/cmd_lib.chm DESTINATION docs/doxygendocuments)
    
		else()
			message ("Doxygen not found !!")
		endif()
  endif()
endfunction()
