# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zachary/Desktop/Science

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zachary/Desktop/Science/build

# Include any dependencies generated for this target.
include CMakeFiles/Science.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Science.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Science.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Science.dir/flags.make

CMakeFiles/Science.dir/driver.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/driver.cpp.o: /Users/zachary/Desktop/Science/driver.cpp
CMakeFiles/Science.dir/driver.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Science.dir/driver.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/driver.cpp.o -MF CMakeFiles/Science.dir/driver.cpp.o.d -o CMakeFiles/Science.dir/driver.cpp.o -c /Users/zachary/Desktop/Science/driver.cpp

CMakeFiles/Science.dir/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/driver.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/driver.cpp > CMakeFiles/Science.dir/driver.cpp.i

CMakeFiles/Science.dir/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/driver.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/driver.cpp -o CMakeFiles/Science.dir/driver.cpp.s

CMakeFiles/Science.dir/src/render/Camera2D.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Camera2D.cpp.o: /Users/zachary/Desktop/Science/src/render/Camera2D.cpp
CMakeFiles/Science.dir/src/render/Camera2D.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Science.dir/src/render/Camera2D.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Camera2D.cpp.o -MF CMakeFiles/Science.dir/src/render/Camera2D.cpp.o.d -o CMakeFiles/Science.dir/src/render/Camera2D.cpp.o -c /Users/zachary/Desktop/Science/src/render/Camera2D.cpp

CMakeFiles/Science.dir/src/render/Camera2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Camera2D.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Camera2D.cpp > CMakeFiles/Science.dir/src/render/Camera2D.cpp.i

CMakeFiles/Science.dir/src/render/Camera2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Camera2D.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Camera2D.cpp -o CMakeFiles/Science.dir/src/render/Camera2D.cpp.s

CMakeFiles/Science.dir/src/render/Circle.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Circle.cpp.o: /Users/zachary/Desktop/Science/src/render/Circle.cpp
CMakeFiles/Science.dir/src/render/Circle.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Science.dir/src/render/Circle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Circle.cpp.o -MF CMakeFiles/Science.dir/src/render/Circle.cpp.o.d -o CMakeFiles/Science.dir/src/render/Circle.cpp.o -c /Users/zachary/Desktop/Science/src/render/Circle.cpp

CMakeFiles/Science.dir/src/render/Circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Circle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Circle.cpp > CMakeFiles/Science.dir/src/render/Circle.cpp.i

CMakeFiles/Science.dir/src/render/Circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Circle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Circle.cpp -o CMakeFiles/Science.dir/src/render/Circle.cpp.s

CMakeFiles/Science.dir/src/render/Controller2D.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Controller2D.cpp.o: /Users/zachary/Desktop/Science/src/render/Controller2D.cpp
CMakeFiles/Science.dir/src/render/Controller2D.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Science.dir/src/render/Controller2D.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Controller2D.cpp.o -MF CMakeFiles/Science.dir/src/render/Controller2D.cpp.o.d -o CMakeFiles/Science.dir/src/render/Controller2D.cpp.o -c /Users/zachary/Desktop/Science/src/render/Controller2D.cpp

CMakeFiles/Science.dir/src/render/Controller2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Controller2D.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Controller2D.cpp > CMakeFiles/Science.dir/src/render/Controller2D.cpp.i

CMakeFiles/Science.dir/src/render/Controller2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Controller2D.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Controller2D.cpp -o CMakeFiles/Science.dir/src/render/Controller2D.cpp.s

CMakeFiles/Science.dir/src/render/Display.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Display.cpp.o: /Users/zachary/Desktop/Science/src/render/Display.cpp
CMakeFiles/Science.dir/src/render/Display.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Science.dir/src/render/Display.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Display.cpp.o -MF CMakeFiles/Science.dir/src/render/Display.cpp.o.d -o CMakeFiles/Science.dir/src/render/Display.cpp.o -c /Users/zachary/Desktop/Science/src/render/Display.cpp

CMakeFiles/Science.dir/src/render/Display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Display.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Display.cpp > CMakeFiles/Science.dir/src/render/Display.cpp.i

CMakeFiles/Science.dir/src/render/Display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Display.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Display.cpp -o CMakeFiles/Science.dir/src/render/Display.cpp.s

CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o: /Users/zachary/Desktop/Science/src/render/ElementBufferObject.cpp
CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o -MF CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o.d -o CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o -c /Users/zachary/Desktop/Science/src/render/ElementBufferObject.cpp

CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/ElementBufferObject.cpp > CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.i

CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/ElementBufferObject.cpp -o CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.s

CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o: /Users/zachary/Desktop/Science/src/render/FirstPersonController.cpp
CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o -MF CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o.d -o CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o -c /Users/zachary/Desktop/Science/src/render/FirstPersonController.cpp

CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/FirstPersonController.cpp > CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.i

CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/FirstPersonController.cpp -o CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.s

CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o: /Users/zachary/Desktop/Science/src/render/FlyCamera.cpp
CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o -MF CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o.d -o CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o -c /Users/zachary/Desktop/Science/src/render/FlyCamera.cpp

CMakeFiles/Science.dir/src/render/FlyCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/FlyCamera.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/FlyCamera.cpp > CMakeFiles/Science.dir/src/render/FlyCamera.cpp.i

CMakeFiles/Science.dir/src/render/FlyCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/FlyCamera.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/FlyCamera.cpp -o CMakeFiles/Science.dir/src/render/FlyCamera.cpp.s

CMakeFiles/Science.dir/src/render/glad.c.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/glad.c.o: /Users/zachary/Desktop/Science/src/render/glad.c
CMakeFiles/Science.dir/src/render/glad.c.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Science.dir/src/render/glad.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/glad.c.o -MF CMakeFiles/Science.dir/src/render/glad.c.o.d -o CMakeFiles/Science.dir/src/render/glad.c.o -c /Users/zachary/Desktop/Science/src/render/glad.c

CMakeFiles/Science.dir/src/render/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Science.dir/src/render/glad.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zachary/Desktop/Science/src/render/glad.c > CMakeFiles/Science.dir/src/render/glad.c.i

CMakeFiles/Science.dir/src/render/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Science.dir/src/render/glad.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zachary/Desktop/Science/src/render/glad.c -o CMakeFiles/Science.dir/src/render/glad.c.s

CMakeFiles/Science.dir/src/render/Line.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Line.cpp.o: /Users/zachary/Desktop/Science/src/render/Line.cpp
CMakeFiles/Science.dir/src/render/Line.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Science.dir/src/render/Line.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Line.cpp.o -MF CMakeFiles/Science.dir/src/render/Line.cpp.o.d -o CMakeFiles/Science.dir/src/render/Line.cpp.o -c /Users/zachary/Desktop/Science/src/render/Line.cpp

CMakeFiles/Science.dir/src/render/Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Line.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Line.cpp > CMakeFiles/Science.dir/src/render/Line.cpp.i

CMakeFiles/Science.dir/src/render/Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Line.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Line.cpp -o CMakeFiles/Science.dir/src/render/Line.cpp.s

CMakeFiles/Science.dir/src/render/Model.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Model.cpp.o: /Users/zachary/Desktop/Science/src/render/Model.cpp
CMakeFiles/Science.dir/src/render/Model.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Science.dir/src/render/Model.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Model.cpp.o -MF CMakeFiles/Science.dir/src/render/Model.cpp.o.d -o CMakeFiles/Science.dir/src/render/Model.cpp.o -c /Users/zachary/Desktop/Science/src/render/Model.cpp

CMakeFiles/Science.dir/src/render/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Model.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Model.cpp > CMakeFiles/Science.dir/src/render/Model.cpp.i

CMakeFiles/Science.dir/src/render/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Model.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Model.cpp -o CMakeFiles/Science.dir/src/render/Model.cpp.s

CMakeFiles/Science.dir/src/render/Rectangle.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Rectangle.cpp.o: /Users/zachary/Desktop/Science/src/render/Rectangle.cpp
CMakeFiles/Science.dir/src/render/Rectangle.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Science.dir/src/render/Rectangle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Rectangle.cpp.o -MF CMakeFiles/Science.dir/src/render/Rectangle.cpp.o.d -o CMakeFiles/Science.dir/src/render/Rectangle.cpp.o -c /Users/zachary/Desktop/Science/src/render/Rectangle.cpp

CMakeFiles/Science.dir/src/render/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Rectangle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Rectangle.cpp > CMakeFiles/Science.dir/src/render/Rectangle.cpp.i

CMakeFiles/Science.dir/src/render/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Rectangle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Rectangle.cpp -o CMakeFiles/Science.dir/src/render/Rectangle.cpp.s

CMakeFiles/Science.dir/src/render/Renderer.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Renderer.cpp.o: /Users/zachary/Desktop/Science/src/render/Renderer.cpp
CMakeFiles/Science.dir/src/render/Renderer.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Science.dir/src/render/Renderer.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Renderer.cpp.o -MF CMakeFiles/Science.dir/src/render/Renderer.cpp.o.d -o CMakeFiles/Science.dir/src/render/Renderer.cpp.o -c /Users/zachary/Desktop/Science/src/render/Renderer.cpp

CMakeFiles/Science.dir/src/render/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Renderer.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Renderer.cpp > CMakeFiles/Science.dir/src/render/Renderer.cpp.i

CMakeFiles/Science.dir/src/render/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Renderer.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Renderer.cpp -o CMakeFiles/Science.dir/src/render/Renderer.cpp.s

CMakeFiles/Science.dir/src/render/Scene.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Scene.cpp.o: /Users/zachary/Desktop/Science/src/render/Scene.cpp
CMakeFiles/Science.dir/src/render/Scene.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Science.dir/src/render/Scene.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Scene.cpp.o -MF CMakeFiles/Science.dir/src/render/Scene.cpp.o.d -o CMakeFiles/Science.dir/src/render/Scene.cpp.o -c /Users/zachary/Desktop/Science/src/render/Scene.cpp

CMakeFiles/Science.dir/src/render/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Scene.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Scene.cpp > CMakeFiles/Science.dir/src/render/Scene.cpp.i

CMakeFiles/Science.dir/src/render/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Scene.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Scene.cpp -o CMakeFiles/Science.dir/src/render/Scene.cpp.s

CMakeFiles/Science.dir/src/render/Shader.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/Shader.cpp.o: /Users/zachary/Desktop/Science/src/render/Shader.cpp
CMakeFiles/Science.dir/src/render/Shader.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Science.dir/src/render/Shader.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/Shader.cpp.o -MF CMakeFiles/Science.dir/src/render/Shader.cpp.o.d -o CMakeFiles/Science.dir/src/render/Shader.cpp.o -c /Users/zachary/Desktop/Science/src/render/Shader.cpp

CMakeFiles/Science.dir/src/render/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/Shader.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/Shader.cpp > CMakeFiles/Science.dir/src/render/Shader.cpp.i

CMakeFiles/Science.dir/src/render/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/Shader.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/Shader.cpp -o CMakeFiles/Science.dir/src/render/Shader.cpp.s

CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o: /Users/zachary/Desktop/Science/src/render/VertexArrayObject.cpp
CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o -MF CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o.d -o CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o -c /Users/zachary/Desktop/Science/src/render/VertexArrayObject.cpp

CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/VertexArrayObject.cpp > CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.i

CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/VertexArrayObject.cpp -o CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.s

CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o: /Users/zachary/Desktop/Science/src/render/VertexBufferObject.cpp
CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o -MF CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o.d -o CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o -c /Users/zachary/Desktop/Science/src/render/VertexBufferObject.cpp

CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/VertexBufferObject.cpp > CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.i

CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/VertexBufferObject.cpp -o CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.s

CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o: /Users/zachary/Desktop/Science/src/render/CoordinateSystem2D.cpp
CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o -MF CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o.d -o CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o -c /Users/zachary/Desktop/Science/src/render/CoordinateSystem2D.cpp

CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/render/CoordinateSystem2D.cpp > CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.i

CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/render/CoordinateSystem2D.cpp -o CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.s

CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o: /Users/zachary/Desktop/Science/src/physics/PeriodicTable.cpp
CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o -MF CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o.d -o CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o -c /Users/zachary/Desktop/Science/src/physics/PeriodicTable.cpp

CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/physics/PeriodicTable.cpp > CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.i

CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/physics/PeriodicTable.cpp -o CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.s

CMakeFiles/Science.dir/src/physics/Atom.cpp.o: CMakeFiles/Science.dir/flags.make
CMakeFiles/Science.dir/src/physics/Atom.cpp.o: /Users/zachary/Desktop/Science/src/physics/Atom.cpp
CMakeFiles/Science.dir/src/physics/Atom.cpp.o: CMakeFiles/Science.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/Science.dir/src/physics/Atom.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Science.dir/src/physics/Atom.cpp.o -MF CMakeFiles/Science.dir/src/physics/Atom.cpp.o.d -o CMakeFiles/Science.dir/src/physics/Atom.cpp.o -c /Users/zachary/Desktop/Science/src/physics/Atom.cpp

CMakeFiles/Science.dir/src/physics/Atom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Science.dir/src/physics/Atom.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zachary/Desktop/Science/src/physics/Atom.cpp > CMakeFiles/Science.dir/src/physics/Atom.cpp.i

CMakeFiles/Science.dir/src/physics/Atom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Science.dir/src/physics/Atom.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zachary/Desktop/Science/src/physics/Atom.cpp -o CMakeFiles/Science.dir/src/physics/Atom.cpp.s

# Object files for target Science
Science_OBJECTS = \
"CMakeFiles/Science.dir/driver.cpp.o" \
"CMakeFiles/Science.dir/src/render/Camera2D.cpp.o" \
"CMakeFiles/Science.dir/src/render/Circle.cpp.o" \
"CMakeFiles/Science.dir/src/render/Controller2D.cpp.o" \
"CMakeFiles/Science.dir/src/render/Display.cpp.o" \
"CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o" \
"CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o" \
"CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o" \
"CMakeFiles/Science.dir/src/render/glad.c.o" \
"CMakeFiles/Science.dir/src/render/Line.cpp.o" \
"CMakeFiles/Science.dir/src/render/Model.cpp.o" \
"CMakeFiles/Science.dir/src/render/Rectangle.cpp.o" \
"CMakeFiles/Science.dir/src/render/Renderer.cpp.o" \
"CMakeFiles/Science.dir/src/render/Scene.cpp.o" \
"CMakeFiles/Science.dir/src/render/Shader.cpp.o" \
"CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o" \
"CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o" \
"CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o" \
"CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o" \
"CMakeFiles/Science.dir/src/physics/Atom.cpp.o"

# External object files for target Science
Science_EXTERNAL_OBJECTS =

Science: CMakeFiles/Science.dir/driver.cpp.o
Science: CMakeFiles/Science.dir/src/render/Camera2D.cpp.o
Science: CMakeFiles/Science.dir/src/render/Circle.cpp.o
Science: CMakeFiles/Science.dir/src/render/Controller2D.cpp.o
Science: CMakeFiles/Science.dir/src/render/Display.cpp.o
Science: CMakeFiles/Science.dir/src/render/ElementBufferObject.cpp.o
Science: CMakeFiles/Science.dir/src/render/FirstPersonController.cpp.o
Science: CMakeFiles/Science.dir/src/render/FlyCamera.cpp.o
Science: CMakeFiles/Science.dir/src/render/glad.c.o
Science: CMakeFiles/Science.dir/src/render/Line.cpp.o
Science: CMakeFiles/Science.dir/src/render/Model.cpp.o
Science: CMakeFiles/Science.dir/src/render/Rectangle.cpp.o
Science: CMakeFiles/Science.dir/src/render/Renderer.cpp.o
Science: CMakeFiles/Science.dir/src/render/Scene.cpp.o
Science: CMakeFiles/Science.dir/src/render/Shader.cpp.o
Science: CMakeFiles/Science.dir/src/render/VertexArrayObject.cpp.o
Science: CMakeFiles/Science.dir/src/render/VertexBufferObject.cpp.o
Science: CMakeFiles/Science.dir/src/render/CoordinateSystem2D.cpp.o
Science: CMakeFiles/Science.dir/src/physics/PeriodicTable.cpp.o
Science: CMakeFiles/Science.dir/src/physics/Atom.cpp.o
Science: CMakeFiles/Science.dir/build.make
Science: /usr/local/lib/libglfw.3.3.dylib
Science: CMakeFiles/Science.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zachary/Desktop/Science/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX executable Science"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Science.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Science.dir/build: Science
.PHONY : CMakeFiles/Science.dir/build

CMakeFiles/Science.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Science.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Science.dir/clean

CMakeFiles/Science.dir/depend:
	cd /Users/zachary/Desktop/Science/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zachary/Desktop/Science /Users/zachary/Desktop/Science /Users/zachary/Desktop/Science/build /Users/zachary/Desktop/Science/build /Users/zachary/Desktop/Science/build/CMakeFiles/Science.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Science.dir/depend

