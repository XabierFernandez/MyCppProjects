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
CMAKE_SOURCE_DIR = /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/build

# Include any dependencies generated for this target.
include CMakeFiles/largestProductOfDigits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/largestProductOfDigits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/largestProductOfDigits.dir/flags.make

CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.o: CMakeFiles/largestProductOfDigits.dir/flags.make
CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.o: ../largestProductOfDigits.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.o -c /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/largestProductOfDigits.cpp

CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/largestProductOfDigits.cpp > CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.i

CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/largestProductOfDigits.cpp -o CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.s

# Object files for target largestProductOfDigits
largestProductOfDigits_OBJECTS = \
"CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.o"

# External object files for target largestProductOfDigits
largestProductOfDigits_EXTERNAL_OBJECTS =

largestProductOfDigits: CMakeFiles/largestProductOfDigits.dir/largestProductOfDigits.cpp.o
largestProductOfDigits: CMakeFiles/largestProductOfDigits.dir/build.make
largestProductOfDigits: CMakeFiles/largestProductOfDigits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable largestProductOfDigits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/largestProductOfDigits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/largestProductOfDigits.dir/build: largestProductOfDigits

.PHONY : CMakeFiles/largestProductOfDigits.dir/build

CMakeFiles/largestProductOfDigits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/largestProductOfDigits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/largestProductOfDigits.dir/clean

CMakeFiles/largestProductOfDigits.dir/depend:
	cd /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/build /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/build /home/xabier/Git_repos/MyCppProjects/LargestProductOfDigits/build/CMakeFiles/largestProductOfDigits.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/largestProductOfDigits.dir/depend
