# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\it_cs\JetBrains\C++\GenerationMethod

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\it_cs\JetBrains\C++\GenerationMethod\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj: ../Arrangement/Arrangement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\it_cs\JetBrains\C++\GenerationMethod\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled.dir\Arrangement\Arrangement.cpp.obj -c E:\it_cs\JetBrains\C++\GenerationMethod\Arrangement\Arrangement.cpp

CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\it_cs\JetBrains\C++\GenerationMethod\Arrangement\Arrangement.cpp > CMakeFiles\untitled.dir\Arrangement\Arrangement.cpp.i

CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\it_cs\JetBrains\C++\GenerationMethod\Arrangement\Arrangement.cpp -o CMakeFiles\untitled.dir\Arrangement\Arrangement.cpp.s

CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.requires:

.PHONY : CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.requires

CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.provides: CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.requires
	$(MAKE) -f CMakeFiles\untitled.dir\build.make CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.provides.build
.PHONY : CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.provides

CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.provides.build: CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj


# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled.exe: CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj
untitled.exe: CMakeFiles/untitled.dir/build.make
untitled.exe: CMakeFiles/untitled.dir/linklibs.rsp
untitled.exe: CMakeFiles/untitled.dir/objects1.rsp
untitled.exe: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\it_cs\JetBrains\C++\GenerationMethod\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable untitled.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled.exe

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/requires: CMakeFiles/untitled.dir/Arrangement/Arrangement.cpp.obj.requires

.PHONY : CMakeFiles/untitled.dir/requires

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\it_cs\JetBrains\C++\GenerationMethod E:\it_cs\JetBrains\C++\GenerationMethod E:\it_cs\JetBrains\C++\GenerationMethod\cmake-build-debug E:\it_cs\JetBrains\C++\GenerationMethod\cmake-build-debug E:\it_cs\JetBrains\C++\GenerationMethod\cmake-build-debug\CMakeFiles\untitled.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend
