# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xabier/Git_repos/MyCppProjects/Different_summands

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xabier/Git_repos/MyCppProjects/Different_summands/build

# Include any dependencies generated for this target.
include CMakeFiles/different_summands.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/different_summands.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/different_summands.dir/flags.make

CMakeFiles/different_summands.dir/different_summands.cpp.o: CMakeFiles/different_summands.dir/flags.make
CMakeFiles/different_summands.dir/different_summands.cpp.o: ../different_summands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xabier/Git_repos/MyCppProjects/Different_summands/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/different_summands.dir/different_summands.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/different_summands.dir/different_summands.cpp.o -c /home/xabier/Git_repos/MyCppProjects/Different_summands/different_summands.cpp

CMakeFiles/different_summands.dir/different_summands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/different_summands.dir/different_summands.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xabier/Git_repos/MyCppProjects/Different_summands/different_summands.cpp > CMakeFiles/different_summands.dir/different_summands.cpp.i

CMakeFiles/different_summands.dir/different_summands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/different_summands.dir/different_summands.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xabier/Git_repos/MyCppProjects/Different_summands/different_summands.cpp -o CMakeFiles/different_summands.dir/different_summands.cpp.s

# Object files for target different_summands
different_summands_OBJECTS = \
"CMakeFiles/different_summands.dir/different_summands.cpp.o"

# External object files for target different_summands
different_summands_EXTERNAL_OBJECTS =

different_summands: CMakeFiles/different_summands.dir/different_summands.cpp.o
different_summands: CMakeFiles/different_summands.dir/build.make
different_summands: CMakeFiles/different_summands.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xabier/Git_repos/MyCppProjects/Different_summands/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable different_summands"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/different_summands.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/different_summands.dir/build: different_summands

.PHONY : CMakeFiles/different_summands.dir/build

CMakeFiles/different_summands.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/different_summands.dir/cmake_clean.cmake
.PHONY : CMakeFiles/different_summands.dir/clean

CMakeFiles/different_summands.dir/depend:
	cd /home/xabier/Git_repos/MyCppProjects/Different_summands/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xabier/Git_repos/MyCppProjects/Different_summands /home/xabier/Git_repos/MyCppProjects/Different_summands /home/xabier/Git_repos/MyCppProjects/Different_summands/build /home/xabier/Git_repos/MyCppProjects/Different_summands/build /home/xabier/Git_repos/MyCppProjects/Different_summands/build/CMakeFiles/different_summands.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/different_summands.dir/depend
