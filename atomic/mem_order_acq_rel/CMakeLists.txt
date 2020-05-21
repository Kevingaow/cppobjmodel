cmake_minimum_required(VERSION 3.10)
project(acq_rel)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(acq_rel main.cpp)
