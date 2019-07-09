include_directories(${PROJECT_SOURCE_DIR}/commandlineparser/include)

link_directories(${PROJECT_SOURCE_DIR}/commandlineparser/src)

add_executable(SampleApp sample_user.cpp)

target_link_libraries(SampleApp mylib)

install(TARGETS SampleApp DESTINATION "${PROJECT_SOURCE_DIR}/install/bin")
