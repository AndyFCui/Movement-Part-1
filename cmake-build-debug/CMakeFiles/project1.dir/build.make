# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\SoftwareApplication\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\SoftwareApplication\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/project1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1.dir/flags.make

CMakeFiles/project1.dir/src/Project1.cpp.obj: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/src/Project1.cpp.obj: ../src/Project1.cpp
CMakeFiles/project1.dir/src/Project1.cpp.obj: CMakeFiles/project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project1.dir/src/Project1.cpp.obj"
	"D:\SoftwareApplication\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project1.dir/src/Project1.cpp.obj -MF CMakeFiles\project1.dir\src\Project1.cpp.obj.d -o CMakeFiles\project1.dir\src\Project1.cpp.obj -c "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\src\Project1.cpp"

CMakeFiles/project1.dir/src/Project1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/src/Project1.cpp.i"
	"D:\SoftwareApplication\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\src\Project1.cpp" > CMakeFiles\project1.dir\src\Project1.cpp.i

CMakeFiles/project1.dir/src/Project1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/src/Project1.cpp.s"
	"D:\SoftwareApplication\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\src\Project1.cpp" -o CMakeFiles\project1.dir\src\Project1.cpp.s

# Object files for target project1
project1_OBJECTS = \
"CMakeFiles/project1.dir/src/Project1.cpp.obj"

# External object files for target project1
project1_EXTERNAL_OBJECTS =

project1.exe: CMakeFiles/project1.dir/src/Project1.cpp.obj
project1.exe: CMakeFiles/project1.dir/build.make
project1.exe: CMakeFiles/project1.dir/linklibs.rsp
project1.exe: CMakeFiles/project1.dir/objects1.rsp
project1.exe: CMakeFiles/project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable project1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1.dir/build: project1.exe
.PHONY : CMakeFiles/project1.dir/build

CMakeFiles/project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project1.dir/clean

CMakeFiles/project1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1" "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1" "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\cmake-build-debug" "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\cmake-build-debug" "F:\OneDrive\NEU\Khoury\Spring 2022\CS5150 Game Artificial Intelligence\project1\Project1\Project1\cmake-build-debug\CMakeFiles\project1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/project1.dir/depend

