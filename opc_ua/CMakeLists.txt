cmake_minimum_required(VERSION 3.10)
project(OPCUATest C)

# Add the open62541 library from the subdirectory.
add_subdirectory(open62541)

# Create the executable from your source file.
add_executable(opc_ua_test opc_ua_test.c)

# Link your executable with the open62541 library.
target_link_libraries(opc_ua_test open62541)




