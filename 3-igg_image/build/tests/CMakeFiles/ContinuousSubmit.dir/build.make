# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/build"

# Utility rule file for ContinuousSubmit.

# Include the progress variables for this target.
include tests/CMakeFiles/ContinuousSubmit.dir/progress.make

tests/CMakeFiles/ContinuousSubmit:
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/build/tests" && /usr/bin/ctest -D ContinuousSubmit

ContinuousSubmit: tests/CMakeFiles/ContinuousSubmit
ContinuousSubmit: tests/CMakeFiles/ContinuousSubmit.dir/build.make

.PHONY : ContinuousSubmit

# Rule to build all files generated by this target.
tests/CMakeFiles/ContinuousSubmit.dir/build: ContinuousSubmit

.PHONY : tests/CMakeFiles/ContinuousSubmit.dir/build

tests/CMakeFiles/ContinuousSubmit.dir/clean:
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousSubmit.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ContinuousSubmit.dir/clean

tests/CMakeFiles/ContinuousSubmit.dir/depend:
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/tests" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/build" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/build/tests" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/3-igg_image/build/tests/CMakeFiles/ContinuousSubmit.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/ContinuousSubmit.dir/depend

