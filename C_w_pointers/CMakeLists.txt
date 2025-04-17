# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and language
project(C_w_pointers)


# Set the C standard (optional)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define an executable target with the source file hello_world.c
add_executable(hello_world hello_world.c)

