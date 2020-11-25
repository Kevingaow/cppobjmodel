cmake_minimum_required(VERSION 3.10)
project(deque-dtor)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)

add_executable(deque-dtor main.cpp)
