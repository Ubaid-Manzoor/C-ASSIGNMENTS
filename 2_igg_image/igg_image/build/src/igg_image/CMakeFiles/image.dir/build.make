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
CMAKE_SOURCE_DIR = "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build"

# Include any dependencies generated for this target.
include src/igg_image/CMakeFiles/image.dir/depend.make

# Include the progress variables for this target.
include src/igg_image/CMakeFiles/image.dir/progress.make

# Include the compile flags for this target's objects.
include src/igg_image/CMakeFiles/image.dir/flags.make

src/igg_image/CMakeFiles/image.dir/image.cpp.o: src/igg_image/CMakeFiles/image.dir/flags.make
src/igg_image/CMakeFiles/image.dir/image.cpp.o: ../src/igg_image/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/igg_image/CMakeFiles/image.dir/image.cpp.o"
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/image.cpp.o -c "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/src/igg_image/image.cpp"

src/igg_image/CMakeFiles/image.dir/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/image.cpp.i"
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/src/igg_image/image.cpp" > CMakeFiles/image.dir/image.cpp.i

src/igg_image/CMakeFiles/image.dir/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/image.cpp.s"
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/src/igg_image/image.cpp" -o CMakeFiles/image.dir/image.cpp.s

src/igg_image/CMakeFiles/image.dir/image.cpp.o.requires:

.PHONY : src/igg_image/CMakeFiles/image.dir/image.cpp.o.requires

src/igg_image/CMakeFiles/image.dir/image.cpp.o.provides: src/igg_image/CMakeFiles/image.dir/image.cpp.o.requires
	$(MAKE) -f src/igg_image/CMakeFiles/image.dir/build.make src/igg_image/CMakeFiles/image.dir/image.cpp.o.provides.build
.PHONY : src/igg_image/CMakeFiles/image.dir/image.cpp.o.provides

src/igg_image/CMakeFiles/image.dir/image.cpp.o.provides.build: src/igg_image/CMakeFiles/image.dir/image.cpp.o


# Object files for target image
image_OBJECTS = \
"CMakeFiles/image.dir/image.cpp.o"

# External object files for target image
image_EXTERNAL_OBJECTS =

../lib/libimage.a: src/igg_image/CMakeFiles/image.dir/image.cpp.o
../lib/libimage.a: src/igg_image/CMakeFiles/image.dir/build.make
../lib/libimage.a: src/igg_image/CMakeFiles/image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libimage.a"
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image" && $(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean_target.cmake
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/igg_image/CMakeFiles/image.dir/build: ../lib/libimage.a

.PHONY : src/igg_image/CMakeFiles/image.dir/build

src/igg_image/CMakeFiles/image.dir/requires: src/igg_image/CMakeFiles/image.dir/image.cpp.o.requires

.PHONY : src/igg_image/CMakeFiles/image.dir/requires

src/igg_image/CMakeFiles/image.dir/clean:
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image" && $(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean.cmake
.PHONY : src/igg_image/CMakeFiles/image.dir/clean

src/igg_image/CMakeFiles/image.dir/depend:
	cd "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/src/igg_image" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image" "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/build/src/igg_image/CMakeFiles/image.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/igg_image/CMakeFiles/image.dir/depend

