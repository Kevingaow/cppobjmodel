cmake_minimum_required(VERSION 3.10)
project(inherit)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)

add_executable(inherit main.cpp)
