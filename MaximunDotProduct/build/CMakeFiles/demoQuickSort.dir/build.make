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
CMAKE_SOURCE_DIR = /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/build

# Include any dependencies generated for this target.
include CMakeFiles/demoQuickSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demoQuickSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demoQuickSort.dir/flags.make

CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.o: CMakeFiles/demoQuickSort.dir/flags.make
CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.o: ../demoQuickSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.o -c /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/demoQuickSort.cpp

CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/demoQuickSort.cpp > CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.i

CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/demoQuickSort.cpp -o CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.s

# Object files for target demoQuickSort
demoQuickSort_OBJECTS = \
"CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.o"

# External object files for target demoQuickSort
demoQuickSort_EXTERNAL_OBJECTS =

demoQuickSort: CMakeFiles/demoQuickSort.dir/demoQuickSort.cpp.o
demoQuickSort: CMakeFiles/demoQuickSort.dir/build.make
demoQuickSort: CMakeFiles/demoQuickSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable demoQuickSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demoQuickSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demoQuickSort.dir/build: demoQuickSort

.PHONY : CMakeFiles/demoQuickSort.dir/build

CMakeFiles/demoQuickSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demoQuickSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demoQuickSort.dir/clean

CMakeFiles/demoQuickSort.dir/depend:
	cd /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/build /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/build /home/xabier/Git_repos/MyCppProjects/MaximunDotProduct/build/CMakeFiles/demoQuickSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demoQuickSort.dir/depend

