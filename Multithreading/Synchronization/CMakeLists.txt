cmake_minimum_required(VERSION 3.0.0)
project(Multithreading VERSION 0.1.0)

set(CMAKE_CXX_FLAGS_DEBUG  "-g")
set(CMAKE_CXX_STANDARD 17)

add_executable(synchronization synchronization.cpp)


