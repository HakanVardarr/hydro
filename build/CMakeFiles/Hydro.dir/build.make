# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hakanvardar/Programming/C++/Hydro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hakanvardar/Programming/C++/Hydro/build

# Include any dependencies generated for this target.
include CMakeFiles/Hydro.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Hydro.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Hydro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hydro.dir/flags.make

CMakeFiles/Hydro.dir/main.cc.o: CMakeFiles/Hydro.dir/flags.make
CMakeFiles/Hydro.dir/main.cc.o: /Users/hakanvardar/Programming/C++/Hydro/main.cc
CMakeFiles/Hydro.dir/main.cc.o: CMakeFiles/Hydro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/hakanvardar/Programming/C++/Hydro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hydro.dir/main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Hydro.dir/main.cc.o -MF CMakeFiles/Hydro.dir/main.cc.o.d -o CMakeFiles/Hydro.dir/main.cc.o -c /Users/hakanvardar/Programming/C++/Hydro/main.cc

CMakeFiles/Hydro.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Hydro.dir/main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hakanvardar/Programming/C++/Hydro/main.cc > CMakeFiles/Hydro.dir/main.cc.i

CMakeFiles/Hydro.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Hydro.dir/main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hakanvardar/Programming/C++/Hydro/main.cc -o CMakeFiles/Hydro.dir/main.cc.s

CMakeFiles/Hydro.dir/vendor/glad.c.o: CMakeFiles/Hydro.dir/flags.make
CMakeFiles/Hydro.dir/vendor/glad.c.o: /Users/hakanvardar/Programming/C++/Hydro/vendor/glad.c
CMakeFiles/Hydro.dir/vendor/glad.c.o: CMakeFiles/Hydro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/hakanvardar/Programming/C++/Hydro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Hydro.dir/vendor/glad.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Hydro.dir/vendor/glad.c.o -MF CMakeFiles/Hydro.dir/vendor/glad.c.o.d -o CMakeFiles/Hydro.dir/vendor/glad.c.o -c /Users/hakanvardar/Programming/C++/Hydro/vendor/glad.c

CMakeFiles/Hydro.dir/vendor/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Hydro.dir/vendor/glad.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hakanvardar/Programming/C++/Hydro/vendor/glad.c > CMakeFiles/Hydro.dir/vendor/glad.c.i

CMakeFiles/Hydro.dir/vendor/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Hydro.dir/vendor/glad.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hakanvardar/Programming/C++/Hydro/vendor/glad.c -o CMakeFiles/Hydro.dir/vendor/glad.c.s

# Object files for target Hydro
Hydro_OBJECTS = \
"CMakeFiles/Hydro.dir/main.cc.o" \
"CMakeFiles/Hydro.dir/vendor/glad.c.o"

# External object files for target Hydro
Hydro_EXTERNAL_OBJECTS =

Hydro: CMakeFiles/Hydro.dir/main.cc.o
Hydro: CMakeFiles/Hydro.dir/vendor/glad.c.o
Hydro: CMakeFiles/Hydro.dir/build.make
Hydro: _deps/glfw-build/src/libglfw3.a
Hydro: CMakeFiles/Hydro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/hakanvardar/Programming/C++/Hydro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Hydro"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Hydro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hydro.dir/build: Hydro
.PHONY : CMakeFiles/Hydro.dir/build

CMakeFiles/Hydro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Hydro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Hydro.dir/clean

CMakeFiles/Hydro.dir/depend:
	cd /Users/hakanvardar/Programming/C++/Hydro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hakanvardar/Programming/C++/Hydro /Users/hakanvardar/Programming/C++/Hydro /Users/hakanvardar/Programming/C++/Hydro/build /Users/hakanvardar/Programming/C++/Hydro/build /Users/hakanvardar/Programming/C++/Hydro/build/CMakeFiles/Hydro.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Hydro.dir/depend

