# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/macs/Desktop/Projects/C++/tqEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/macs/Desktop/Projects/C++/tqEngine/build

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include lib/glfw/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/glfw/CMakeFiles/uninstall.dir/progress.make

lib/glfw/CMakeFiles/uninstall:
	cd /home/macs/Desktop/Projects/C++/tqEngine/build/lib/glfw && /usr/bin/cmake -P /home/macs/Desktop/Projects/C++/tqEngine/build/lib/glfw/cmake_uninstall.cmake

uninstall: lib/glfw/CMakeFiles/uninstall
uninstall: lib/glfw/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
lib/glfw/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : lib/glfw/CMakeFiles/uninstall.dir/build

lib/glfw/CMakeFiles/uninstall.dir/clean:
	cd /home/macs/Desktop/Projects/C++/tqEngine/build/lib/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : lib/glfw/CMakeFiles/uninstall.dir/clean

lib/glfw/CMakeFiles/uninstall.dir/depend:
	cd /home/macs/Desktop/Projects/C++/tqEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/macs/Desktop/Projects/C++/tqEngine /home/macs/Desktop/Projects/C++/tqEngine/lib/glfw /home/macs/Desktop/Projects/C++/tqEngine/build /home/macs/Desktop/Projects/C++/tqEngine/build/lib/glfw /home/macs/Desktop/Projects/C++/tqEngine/build/lib/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/CMakeFiles/uninstall.dir/depend

