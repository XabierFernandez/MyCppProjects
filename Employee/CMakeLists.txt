cmake_minimum_required(VERSION 3.27.0)

project(Employee VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)

# Set the compiler flags for the Debug build
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

add_executable(employee employee.cpp)
