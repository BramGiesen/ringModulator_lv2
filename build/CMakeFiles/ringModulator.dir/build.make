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
CMAKE_SOURCE_DIR = /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/build

# Include any dependencies generated for this target.
include CMakeFiles/ringModulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ringModulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ringModulator.dir/flags.make

CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o: CMakeFiles/ringModulator.dir/flags.make
CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o: ../src/audioProcess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o -c /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/src/audioProcess.cpp

CMakeFiles/ringModulator.dir/src/audioProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ringModulator.dir/src/audioProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/src/audioProcess.cpp > CMakeFiles/ringModulator.dir/src/audioProcess.cpp.i

CMakeFiles/ringModulator.dir/src/audioProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ringModulator.dir/src/audioProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/src/audioProcess.cpp -o CMakeFiles/ringModulator.dir/src/audioProcess.cpp.s

CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.requires:

.PHONY : CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.requires

CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.provides: CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.requires
	$(MAKE) -f CMakeFiles/ringModulator.dir/build.make CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.provides.build
.PHONY : CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.provides

CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.provides.build: CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o


# Object files for target ringModulator
ringModulator_OBJECTS = \
"CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o"

# External object files for target ringModulator
ringModulator_EXTERNAL_OBJECTS =

ringModulator.lv2/libringModulator.so: CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o
ringModulator.lv2/libringModulator.so: CMakeFiles/ringModulator.dir/build.make
ringModulator.lv2/libringModulator.so: CMakeFiles/ringModulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module ringModulator.lv2/libringModulator.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ringModulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ringModulator.dir/build: ringModulator.lv2/libringModulator.so

.PHONY : CMakeFiles/ringModulator.dir/build

CMakeFiles/ringModulator.dir/requires: CMakeFiles/ringModulator.dir/src/audioProcess.cpp.o.requires

.PHONY : CMakeFiles/ringModulator.dir/requires

CMakeFiles/ringModulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ringModulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ringModulator.dir/clean

CMakeFiles/ringModulator.dir/depend:
	cd /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2 /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2 /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/build /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/build /home/bramgiesen/Programming/MOD/plugins/ringModulator.lv2/build/CMakeFiles/ringModulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ringModulator.dir/depend

