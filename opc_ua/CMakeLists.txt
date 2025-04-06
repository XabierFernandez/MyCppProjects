cmake_minimum_required(VERSION 3.10)

# Forcing Clang on Windows (adjust paths if necessary)
set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang.exe" CACHE STRING "C Compiler" FORCE)
set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++.exe" CACHE STRING "C++ Compiler" FORCE)

project(OPCUATest C)

# Do not define UA_ENABLE_AMALGAMATION if you want the regular build
add_subdirectory(open62541)

add_executable(opc_ua_test opc_ua_test.c)
target_link_libraries(opc_ua_test open62541)
target_include_directories(opc_ua_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/open62541/include
    ${CMAKE_CURRENT_BINARY_DIR}/open62541/src_generated
)

if(WIN32)
    target_link_libraries(opc_ua_test ws2_32 crypt32)
endif()
