cmake_minimum_required(VERSION 3.0.0)
project(Sorting VERSION 0.1.0)

set(CMAKE_CXX_FLAGS_DEBUG  "-g")

add_executable(sorting sorting.cpp)
add_executable(sorting3 sorting3.cpp)
add_executable(inversions inversions.cpp)
add_executable(quicksort quicksort.cpp)
add_executable(points_and_segments points_and_segments.cpp)
