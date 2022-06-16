cmake_minimum_required(VERSION 3.0.0)
project(cpp-spline VERSION 0.1.0)

aux_source_directory(src SRC_FILES) 

add_library(cpp-spline ${SRC_FILES})
target_include_directories(cpp-spline PUBLIC src)

add_executable(test_spline test/main.cpp)
target_link_libraries(test_spline cpp-spline)


add_subdirectory("test/qt") 


