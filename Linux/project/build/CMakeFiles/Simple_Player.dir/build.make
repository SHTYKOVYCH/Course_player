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
CMAKE_SOURCE_DIR = /home/dimitis/Yandex.Disk/labs/Course_work_hl/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build

# Include any dependencies generated for this target.
include CMakeFiles/Simple_Player.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Simple_Player.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Simple_Player.dir/flags.make

CMakeFiles/Simple_Player.dir/executable/main.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/main.c.o: ../executable/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Simple_Player.dir/executable/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/main.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/main.c

CMakeFiles/Simple_Player.dir/executable/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/main.c > CMakeFiles/Simple_Player.dir/executable/main.c.i

CMakeFiles/Simple_Player.dir/executable/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/main.c -o CMakeFiles/Simple_Player.dir/executable/main.c.s

CMakeFiles/Simple_Player.dir/executable/main.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/main.c.o.requires

CMakeFiles/Simple_Player.dir/executable/main.c.o.provides: CMakeFiles/Simple_Player.dir/executable/main.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/main.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/main.c.o.provides

CMakeFiles/Simple_Player.dir/executable/main.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/main.c.o


CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o: ../executable/OpenFile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/OpenFile.c

CMakeFiles/Simple_Player.dir/executable/OpenFile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/OpenFile.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/OpenFile.c > CMakeFiles/Simple_Player.dir/executable/OpenFile.c.i

CMakeFiles/Simple_Player.dir/executable/OpenFile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/OpenFile.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/OpenFile.c -o CMakeFiles/Simple_Player.dir/executable/OpenFile.c.s

CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.requires

CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.provides: CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.provides

CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o


CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o: ../executable/DecodeError.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/DecodeError.c

CMakeFiles/Simple_Player.dir/executable/DecodeError.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/DecodeError.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/DecodeError.c > CMakeFiles/Simple_Player.dir/executable/DecodeError.c.i

CMakeFiles/Simple_Player.dir/executable/DecodeError.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/DecodeError.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/DecodeError.c -o CMakeFiles/Simple_Player.dir/executable/DecodeError.c.s

CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.requires

CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.provides: CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.provides

CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o


CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o: ../executable/ReadSceneNum.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/ReadSceneNum.c

CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/ReadSceneNum.c > CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.i

CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/ReadSceneNum.c -o CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.s

CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.requires

CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.provides: CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.provides

CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o


CMakeFiles/Simple_Player.dir/executable/Scene.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/Scene.c.o: ../executable/Scene.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Simple_Player.dir/executable/Scene.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/Scene.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Scene.c

CMakeFiles/Simple_Player.dir/executable/Scene.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/Scene.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Scene.c > CMakeFiles/Simple_Player.dir/executable/Scene.c.i

CMakeFiles/Simple_Player.dir/executable/Scene.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/Scene.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Scene.c -o CMakeFiles/Simple_Player.dir/executable/Scene.c.s

CMakeFiles/Simple_Player.dir/executable/Scene.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/Scene.c.o.requires

CMakeFiles/Simple_Player.dir/executable/Scene.c.o.provides: CMakeFiles/Simple_Player.dir/executable/Scene.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/Scene.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/Scene.c.o.provides

CMakeFiles/Simple_Player.dir/executable/Scene.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/Scene.c.o


CMakeFiles/Simple_Player.dir/executable/Check.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/Check.c.o: ../executable/Check.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Simple_Player.dir/executable/Check.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/Check.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Check.c

CMakeFiles/Simple_Player.dir/executable/Check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/Check.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Check.c > CMakeFiles/Simple_Player.dir/executable/Check.c.i

CMakeFiles/Simple_Player.dir/executable/Check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/Check.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Check.c -o CMakeFiles/Simple_Player.dir/executable/Check.c.s

CMakeFiles/Simple_Player.dir/executable/Check.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/Check.c.o.requires

CMakeFiles/Simple_Player.dir/executable/Check.c.o.provides: CMakeFiles/Simple_Player.dir/executable/Check.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/Check.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/Check.c.o.provides

CMakeFiles/Simple_Player.dir/executable/Check.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/Check.c.o


CMakeFiles/Simple_Player.dir/executable/Sound.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/Sound.c.o: ../executable/Sound.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Simple_Player.dir/executable/Sound.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/Sound.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Sound.c

CMakeFiles/Simple_Player.dir/executable/Sound.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/Sound.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Sound.c > CMakeFiles/Simple_Player.dir/executable/Sound.c.i

CMakeFiles/Simple_Player.dir/executable/Sound.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/Sound.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Sound.c -o CMakeFiles/Simple_Player.dir/executable/Sound.c.s

CMakeFiles/Simple_Player.dir/executable/Sound.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/Sound.c.o.requires

CMakeFiles/Simple_Player.dir/executable/Sound.c.o.provides: CMakeFiles/Simple_Player.dir/executable/Sound.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/Sound.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/Sound.c.o.provides

CMakeFiles/Simple_Player.dir/executable/Sound.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/Sound.c.o


CMakeFiles/Simple_Player.dir/executable/Graphics.c.o: CMakeFiles/Simple_Player.dir/flags.make
CMakeFiles/Simple_Player.dir/executable/Graphics.c.o: ../executable/Graphics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Simple_Player.dir/executable/Graphics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Simple_Player.dir/executable/Graphics.c.o   -c /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Graphics.c

CMakeFiles/Simple_Player.dir/executable/Graphics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple_Player.dir/executable/Graphics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Graphics.c > CMakeFiles/Simple_Player.dir/executable/Graphics.c.i

CMakeFiles/Simple_Player.dir/executable/Graphics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple_Player.dir/executable/Graphics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/executable/Graphics.c -o CMakeFiles/Simple_Player.dir/executable/Graphics.c.s

CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.requires:

.PHONY : CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.requires

CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.provides: CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.requires
	$(MAKE) -f CMakeFiles/Simple_Player.dir/build.make CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.provides.build
.PHONY : CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.provides

CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.provides.build: CMakeFiles/Simple_Player.dir/executable/Graphics.c.o


# Object files for target Simple_Player
Simple_Player_OBJECTS = \
"CMakeFiles/Simple_Player.dir/executable/main.c.o" \
"CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o" \
"CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o" \
"CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o" \
"CMakeFiles/Simple_Player.dir/executable/Scene.c.o" \
"CMakeFiles/Simple_Player.dir/executable/Check.c.o" \
"CMakeFiles/Simple_Player.dir/executable/Sound.c.o" \
"CMakeFiles/Simple_Player.dir/executable/Graphics.c.o"

# External object files for target Simple_Player
Simple_Player_EXTERNAL_OBJECTS =

Simple_Player: CMakeFiles/Simple_Player.dir/executable/main.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/executable/Scene.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/executable/Check.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/executable/Sound.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/executable/Graphics.c.o
Simple_Player: CMakeFiles/Simple_Player.dir/build.make
Simple_Player: CMakeFiles/Simple_Player.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable Simple_Player"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Simple_Player.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Simple_Player.dir/build: Simple_Player

.PHONY : CMakeFiles/Simple_Player.dir/build

CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/main.c.o.requires
CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/OpenFile.c.o.requires
CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/DecodeError.c.o.requires
CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/ReadSceneNum.c.o.requires
CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/Scene.c.o.requires
CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/Check.c.o.requires
CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/Sound.c.o.requires
CMakeFiles/Simple_Player.dir/requires: CMakeFiles/Simple_Player.dir/executable/Graphics.c.o.requires

.PHONY : CMakeFiles/Simple_Player.dir/requires

CMakeFiles/Simple_Player.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Simple_Player.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Simple_Player.dir/clean

CMakeFiles/Simple_Player.dir/depend:
	cd /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dimitis/Yandex.Disk/labs/Course_work_hl/project /home/dimitis/Yandex.Disk/labs/Course_work_hl/project /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build /home/dimitis/Yandex.Disk/labs/Course_work_hl/project/build/CMakeFiles/Simple_Player.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Simple_Player.dir/depend

