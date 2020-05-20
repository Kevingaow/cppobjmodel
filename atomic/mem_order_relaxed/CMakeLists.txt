cmake_minimum_required(VERSION 3.10)
project(relaxed)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(relaxed main.cpp)
