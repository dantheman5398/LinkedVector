# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/dantheman5398/Downloads/clion-2018.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dantheman5398/Downloads/clion-2018.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/sf_CSE250Projects/A2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_CSE250Projects/A2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/a2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a2.dir/flags.make

CMakeFiles/a2.dir/code/main.cpp.o: CMakeFiles/a2.dir/flags.make
CMakeFiles/a2.dir/code/main.cpp.o: ../code/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_CSE250Projects/A2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a2.dir/code/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a2.dir/code/main.cpp.o -c /media/sf_CSE250Projects/A2/code/main.cpp

CMakeFiles/a2.dir/code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a2.dir/code/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_CSE250Projects/A2/code/main.cpp > CMakeFiles/a2.dir/code/main.cpp.i

CMakeFiles/a2.dir/code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a2.dir/code/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_CSE250Projects/A2/code/main.cpp -o CMakeFiles/a2.dir/code/main.cpp.s

# Object files for target a2
a2_OBJECTS = \
"CMakeFiles/a2.dir/code/main.cpp.o"

# External object files for target a2
a2_EXTERNAL_OBJECTS =

a2: CMakeFiles/a2.dir/code/main.cpp.o
a2: CMakeFiles/a2.dir/build.make
a2: CMakeFiles/a2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_CSE250Projects/A2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable a2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a2.dir/build: a2

.PHONY : CMakeFiles/a2.dir/build

CMakeFiles/a2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a2.dir/clean

CMakeFiles/a2.dir/depend:
	cd /media/sf_CSE250Projects/A2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_CSE250Projects/A2 /media/sf_CSE250Projects/A2 /media/sf_CSE250Projects/A2/cmake-build-debug /media/sf_CSE250Projects/A2/cmake-build-debug /media/sf_CSE250Projects/A2/cmake-build-debug/CMakeFiles/a2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a2.dir/depend

