# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/xabier/Git_repos/MyCppProjects/Sorting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xabier/Git_repos/MyCppProjects/Sorting/build

# Include any dependencies generated for this target.
include CMakeFiles/points_and_segments.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/points_and_segments.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/points_and_segments.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/points_and_segments.dir/flags.make

CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o: CMakeFiles/points_and_segments.dir/flags.make
CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o: ../points_and_segments.cpp
CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o: CMakeFiles/points_and_segments.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xabier/Git_repos/MyCppProjects/Sorting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o -MF CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o.d -o CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o -c /home/xabier/Git_repos/MyCppProjects/Sorting/points_and_segments.cpp

CMakeFiles/points_and_segments.dir/points_and_segments.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/points_and_segments.dir/points_and_segments.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xabier/Git_repos/MyCppProjects/Sorting/points_and_segments.cpp > CMakeFiles/points_and_segments.dir/points_and_segments.cpp.i

CMakeFiles/points_and_segments.dir/points_and_segments.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/points_and_segments.dir/points_and_segments.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xabier/Git_repos/MyCppProjects/Sorting/points_and_segments.cpp -o CMakeFiles/points_and_segments.dir/points_and_segments.cpp.s

# Object files for target points_and_segments
points_and_segments_OBJECTS = \
"CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o"

# External object files for target points_and_segments
points_and_segments_EXTERNAL_OBJECTS =

points_and_segments: CMakeFiles/points_and_segments.dir/points_and_segments.cpp.o
points_and_segments: CMakeFiles/points_and_segments.dir/build.make
points_and_segments: CMakeFiles/points_and_segments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xabier/Git_repos/MyCppProjects/Sorting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable points_and_segments"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/points_and_segments.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/points_and_segments.dir/build: points_and_segments
.PHONY : CMakeFiles/points_and_segments.dir/build

CMakeFiles/points_and_segments.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/points_and_segments.dir/cmake_clean.cmake
.PHONY : CMakeFiles/points_and_segments.dir/clean

CMakeFiles/points_and_segments.dir/depend:
	cd /home/xabier/Git_repos/MyCppProjects/Sorting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xabier/Git_repos/MyCppProjects/Sorting /home/xabier/Git_repos/MyCppProjects/Sorting /home/xabier/Git_repos/MyCppProjects/Sorting/build /home/xabier/Git_repos/MyCppProjects/Sorting/build /home/xabier/Git_repos/MyCppProjects/Sorting/build/CMakeFiles/points_and_segments.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/points_and_segments.dir/depend
