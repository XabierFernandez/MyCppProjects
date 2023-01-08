cmake_minimum_required(VERSION 3.0.0)
project(Multithreading VERSION 0.1.0)

set(CMAKE_CXX_FLAGS_DEBUG  "-g")
set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(simple_pthreads simple_pthreads.cpp)

target_link_libraries(simple_pthreads PRIVATE Threads::Threads)
