# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build

# Utility rule file for open62541-generator-statuscode.

# Include any custom commands dependencies for this target.
include open62541/CMakeFiles/open62541-generator-statuscode.dir/compiler_depend.make

# Include the progress variables for this target.
include open62541/CMakeFiles/open62541-generator-statuscode.dir/progress.make

open62541/CMakeFiles/open62541-generator-statuscode: open62541/src_generated/open62541/nodeids.h
open62541/CMakeFiles/open62541-generator-statuscode: open62541/src_generated/open62541/statuscodes.h
open62541/CMakeFiles/open62541-generator-statuscode: open62541/src_generated/open62541/statuscodes.c

open62541/src_generated/open62541/nodeids.h: /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/generate_nodeid_header.py
open62541/src_generated/open62541/nodeids.h: /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/schema/NodeIds.csv
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating src_generated/open62541/nodeids.h"
	cd /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/open62541 && /home/xabier/.pyenv/shims/python3.13 /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/generate_nodeid_header.py /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/schema/NodeIds.csv /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/open62541/src_generated/open62541/nodeids NS0

open62541/src_generated/open62541/statuscodes.h: /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/generate_statuscode_descriptions.py
open62541/src_generated/open62541/statuscodes.h: /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/schema/StatusCode.csv
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating src_generated/open62541/statuscodes.h, src_generated/open62541/statuscodes.c"
	cd /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/open62541 && /home/xabier/.pyenv/shims/python3.13 /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/generate_statuscode_descriptions.py /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541/tools/schema/StatusCode.csv /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/open62541/src_generated/open62541/statuscodes

open62541/src_generated/open62541/statuscodes.c: open62541/src_generated/open62541/statuscodes.h
	@$(CMAKE_COMMAND) -E touch_nocreate open62541/src_generated/open62541/statuscodes.c

open62541-generator-statuscode: open62541/CMakeFiles/open62541-generator-statuscode
open62541-generator-statuscode: open62541/src_generated/open62541/nodeids.h
open62541-generator-statuscode: open62541/src_generated/open62541/statuscodes.c
open62541-generator-statuscode: open62541/src_generated/open62541/statuscodes.h
open62541-generator-statuscode: open62541/CMakeFiles/open62541-generator-statuscode.dir/build.make
.PHONY : open62541-generator-statuscode

# Rule to build all files generated by this target.
open62541/CMakeFiles/open62541-generator-statuscode.dir/build: open62541-generator-statuscode
.PHONY : open62541/CMakeFiles/open62541-generator-statuscode.dir/build

open62541/CMakeFiles/open62541-generator-statuscode.dir/clean:
	cd /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/open62541 && $(CMAKE_COMMAND) -P CMakeFiles/open62541-generator-statuscode.dir/cmake_clean.cmake
.PHONY : open62541/CMakeFiles/open62541-generator-statuscode.dir/clean

open62541/CMakeFiles/open62541-generator-statuscode.dir/depend:
	cd /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/open62541 /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/open62541 /home/xabier/Documents/Gitrepos/MyCppProjects/opc_ua/build/open62541/CMakeFiles/open62541-generator-statuscode.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : open62541/CMakeFiles/open62541-generator-statuscode.dir/depend

