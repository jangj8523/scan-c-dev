# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/jaewoo_work/c_lidar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/jaewoo_work/c_lidar/build

# Include any dependencies generated for this target.
include CMakeFiles/main_exec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main_exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_exec.dir/flags.make

CMakeFiles/main_exec.dir/src/main.c.o: CMakeFiles/main_exec.dir/flags.make
CMakeFiles/main_exec.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/jaewoo_work/c_lidar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main_exec.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main_exec.dir/src/main.c.o   -c /home/pi/jaewoo_work/c_lidar/src/main.c

CMakeFiles/main_exec.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_exec.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/jaewoo_work/c_lidar/src/main.c > CMakeFiles/main_exec.dir/src/main.c.i

CMakeFiles/main_exec.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_exec.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/jaewoo_work/c_lidar/src/main.c -o CMakeFiles/main_exec.dir/src/main.c.s

CMakeFiles/main_exec.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/main_exec.dir/src/main.c.o.requires

CMakeFiles/main_exec.dir/src/main.c.o.provides: CMakeFiles/main_exec.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/main_exec.dir/build.make CMakeFiles/main_exec.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/main_exec.dir/src/main.c.o.provides

CMakeFiles/main_exec.dir/src/main.c.o.provides.build: CMakeFiles/main_exec.dir/src/main.c.o


# Object files for target main_exec
main_exec_OBJECTS = \
"CMakeFiles/main_exec.dir/src/main.c.o"

# External object files for target main_exec
main_exec_EXTERNAL_OBJECTS =

main_exec: CMakeFiles/main_exec.dir/src/main.c.o
main_exec: CMakeFiles/main_exec.dir/build.make
<<<<<<< HEAD
main_exec: ../bin/liblidar.so
=======
main_exec: ../bin/liblidar.dylib
>>>>>>> b233d516c8aeab14877ca2f8c990b0524e2781d6
main_exec: CMakeFiles/main_exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/jaewoo_work/c_lidar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main_exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_exec.dir/build: main_exec

.PHONY : CMakeFiles/main_exec.dir/build

CMakeFiles/main_exec.dir/requires: CMakeFiles/main_exec.dir/src/main.c.o.requires

.PHONY : CMakeFiles/main_exec.dir/requires

CMakeFiles/main_exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_exec.dir/clean

CMakeFiles/main_exec.dir/depend:
	cd /home/pi/jaewoo_work/c_lidar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/jaewoo_work/c_lidar /home/pi/jaewoo_work/c_lidar /home/pi/jaewoo_work/c_lidar/build /home/pi/jaewoo_work/c_lidar/build /home/pi/jaewoo_work/c_lidar/build/CMakeFiles/main_exec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_exec.dir/depend

