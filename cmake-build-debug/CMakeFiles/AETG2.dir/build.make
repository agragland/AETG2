# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Andrew\Documents\Spring2021\AETG2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Andrew\Documents\Spring2021\AETG2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AETG2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AETG2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AETG2.dir/flags.make

CMakeFiles/AETG2.dir/testPairs.cpp.obj: CMakeFiles/AETG2.dir/flags.make
CMakeFiles/AETG2.dir/testPairs.cpp.obj: ../testPairs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrew\Documents\Spring2021\AETG2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AETG2.dir/testPairs.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AETG2.dir\testPairs.cpp.obj -c C:\Users\Andrew\Documents\Spring2021\AETG2\testPairs.cpp

CMakeFiles/AETG2.dir/testPairs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AETG2.dir/testPairs.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andrew\Documents\Spring2021\AETG2\testPairs.cpp > CMakeFiles\AETG2.dir\testPairs.cpp.i

CMakeFiles/AETG2.dir/testPairs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AETG2.dir/testPairs.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Andrew\Documents\Spring2021\AETG2\testPairs.cpp -o CMakeFiles\AETG2.dir\testPairs.cpp.s

# Object files for target AETG2
AETG2_OBJECTS = \
"CMakeFiles/AETG2.dir/testPairs.cpp.obj"

# External object files for target AETG2
AETG2_EXTERNAL_OBJECTS =

AETG2.exe: CMakeFiles/AETG2.dir/testPairs.cpp.obj
AETG2.exe: CMakeFiles/AETG2.dir/build.make
AETG2.exe: CMakeFiles/AETG2.dir/linklibs.rsp
AETG2.exe: CMakeFiles/AETG2.dir/objects1.rsp
AETG2.exe: CMakeFiles/AETG2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Andrew\Documents\Spring2021\AETG2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AETG2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AETG2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AETG2.dir/build: AETG2.exe

.PHONY : CMakeFiles/AETG2.dir/build

CMakeFiles/AETG2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AETG2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AETG2.dir/clean

CMakeFiles/AETG2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Andrew\Documents\Spring2021\AETG2 C:\Users\Andrew\Documents\Spring2021\AETG2 C:\Users\Andrew\Documents\Spring2021\AETG2\cmake-build-debug C:\Users\Andrew\Documents\Spring2021\AETG2\cmake-build-debug C:\Users\Andrew\Documents\Spring2021\AETG2\cmake-build-debug\CMakeFiles\AETG2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AETG2.dir/depend
