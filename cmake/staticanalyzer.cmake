#this is static analysis of the code.
option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" ON)
if(ENABLE_CPPCHECK)
  find_program(CPPCHECK cppcheck)
  if(CPPCHECK)
  file(MAKE_DIRECTORY docs/staticanalyzer)
  set(REPORT_DIR docs/staticanalyzer)
  set(CMAKE_CXX_CPPCHECK_ARGS   --language=c++ --std=c++14 --xml --enable=all  --suppress=missingInclude   ${CMAKE_SOURCE_DIR}/commandlineparser/include/*.h ${CMAKE_SOURCE_DIR}/commandlineparser/src/*.cpp)
  set(CMAKE_CXX_CPPCHECK ${CPPCHECK}   ${CMAKE_CXX_CPPCHECK_ARGS} 2> ${PROJECT_SOURCE_DIR}/${REPORT_DIR}/static_analysis_report.xml )
  
  add_custom_target(
    run_cppcheck
    COMMAND ${CMAKE_CXX_CPPCHECK}
    COMMENT "running cppcheck")

  else()
    message(SEND_ERROR "cppcheck requested but executable not found !")
  endif()

endif()

