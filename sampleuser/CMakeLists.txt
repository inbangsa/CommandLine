include_directories(${PROJECT_SOURCE_DIR}/cmdlineparserlib/include)
link_directories(${PROJECT_SOURCE_DIR}/cmdlineparserlib/src)
add_executable(SampleApp sample_user.cpp)

target_link_libraries(SampleApp mylib)

