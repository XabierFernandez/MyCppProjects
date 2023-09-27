cmake_minimum_required(VERSION 3.0.0)
project(Knapsack VERSION 0.1.0)

set(CMAKE_CXX_FLAGS_DEBUG  "-g")
set(CMAKE_BUILD_TYPE Debug)

add_executable(knapsack  knapsack.cpp)
add_executable(knapsack_2  knapsack_2.cpp)
add_executable(partition_souvenir_3  partition_souvenir_3.cpp)
add_executable(placing_parentheses  placing_parentheses.cpp)