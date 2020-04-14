cmake_minimum_required(VERSION 3.10)
project(auto_gen_def_ctor)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(auto_gen_def_ctor main.cpp)
