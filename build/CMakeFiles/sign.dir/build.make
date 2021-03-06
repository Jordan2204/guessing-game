# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jordan/samples/guessing-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jordan/samples/guessing-game/build

# Utility rule file for sign.

# Include any custom commands dependencies for this target.
include CMakeFiles/sign.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sign.dir/progress.make

CMakeFiles/sign: enclave/enclave.signed

enclave/enclave.signed: enclave/enclave
enclave/enclave.signed: ../enclave/guessing.conf
enclave/enclave.signed: private.pem
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jordan/samples/guessing-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating enclave/enclave.signed"
	/opt/openenclave/bin/oesign sign -e /home/jordan/samples/guessing-game/build/enclave/enclave -c /home/jordan/samples/guessing-game/enclave/guessing.conf -k private.pem

private.pem:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jordan/samples/guessing-game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating private.pem, public.pem"
	openssl genrsa -out private.pem -3 3072
	openssl rsa -in private.pem -pubout -out public.pem

public.pem: private.pem
	@$(CMAKE_COMMAND) -E touch_nocreate public.pem

sign: CMakeFiles/sign
sign: enclave/enclave.signed
sign: private.pem
sign: public.pem
sign: CMakeFiles/sign.dir/build.make
.PHONY : sign

# Rule to build all files generated by this target.
CMakeFiles/sign.dir/build: sign
.PHONY : CMakeFiles/sign.dir/build

CMakeFiles/sign.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sign.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sign.dir/clean

CMakeFiles/sign.dir/depend:
	cd /home/jordan/samples/guessing-game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jordan/samples/guessing-game /home/jordan/samples/guessing-game /home/jordan/samples/guessing-game/build /home/jordan/samples/guessing-game/build /home/jordan/samples/guessing-game/build/CMakeFiles/sign.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sign.dir/depend

