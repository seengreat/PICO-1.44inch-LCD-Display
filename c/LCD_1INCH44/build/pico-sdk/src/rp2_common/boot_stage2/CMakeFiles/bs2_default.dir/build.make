# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\visual studio\ide\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\visual studio\ide\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44\build"

# Include any dependencies generated for this target.
include pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\compiler_depend.make

# Include the progress variables for this target.
include pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\progress.make

# Include the compile flags for this target's objects.
include pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\flags.make

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\compile_time_choice.S.obj: pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\flags.make
pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\compile_time_choice.S.obj: D:\pico-env\pico-sdk\src\rp2_common\boot_stage2\compile_time_choice.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object pico-sdk/src/rp2_common/boot_stage2/CMakeFiles/bs2_default.dir/compile_time_choice.S.obj"
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build\pico-sdk\src\RP2_CO~1\BOOT_S~1
	"D:\9 2019-q4-major\bin\arm-none-eabi-gcc.exe" $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles\bs2_default.dir\compile_time_choice.S.obj   -c D:\pico-env\pico-sdk\src\rp2_common\boot_stage2\compile_time_choice.S
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\compile_time_choice.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing ASM source to CMakeFiles/bs2_default.dir/compile_time_choice.S.i"
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build\pico-sdk\src\RP2_CO~1\BOOT_S~1
	"D:\9 2019-q4-major\bin\arm-none-eabi-gcc.exe" $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E D:\pico-env\pico-sdk\src\rp2_common\boot_stage2\compile_time_choice.S > CMakeFiles\bs2_default.dir\compile_time_choice.S.i
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\compile_time_choice.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling ASM source to assembly CMakeFiles/bs2_default.dir/compile_time_choice.S.s"
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build\pico-sdk\src\RP2_CO~1\BOOT_S~1
	"D:\9 2019-q4-major\bin\arm-none-eabi-gcc.exe" $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S D:\pico-env\pico-sdk\src\rp2_common\boot_stage2\compile_time_choice.S -o CMakeFiles\bs2_default.dir\compile_time_choice.S.s
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build

# Object files for target bs2_default
bs2_default_OBJECTS = \
"CMakeFiles\bs2_default.dir\compile_time_choice.S.obj"

# External object files for target bs2_default
bs2_default_EXTERNAL_OBJECTS =

pico-sdk\src\rp2_common\boot_stage2\bs2_default.elf: pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\compile_time_choice.S.obj
pico-sdk\src\rp2_common\boot_stage2\bs2_default.elf: pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\build.make
pico-sdk\src\rp2_common\boot_stage2\bs2_default.elf: D:\pico-env\pico-sdk\src\rp2_common\boot_stage2\boot_stage2.ld
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking ASM executable bs2_default.elf"
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build\pico-sdk\src\RP2_CO~1\BOOT_S~1
	"D:\9 2019-q4-major\bin\arm-none-eabi-gcc.exe" -mcpu=cortex-m0plus -mthumb -Og -g -Wl,--build-id=none --specs=nosys.specs -nostartfiles -Wl,--script=D:/pico-env/pico-sdk/src/rp2_common/boot_stage2/boot_stage2.ld -Wl,-Map=bs2_default.elf.map $(bs2_default_OBJECTS) $(bs2_default_EXTERNAL_OBJECTS) -o bs2_default.elf 
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build\pico-sdk\src\RP2_CO~1\BOOT_S~1
	echo >nul && "D:\9 2019-q4-major\bin\arm-none-eabi-objdump.exe" -h "E:/lyh/products/PICO-1.44inch-LCD-Display/demo codes/c/LCD_1INCH44/build/pico-sdk/src/rp2_common/boot_stage2/bs2_default.elf" >bs2_default.dis
	echo >nul && "D:\9 2019-q4-major\bin\arm-none-eabi-objdump.exe" -d "E:/lyh/products/PICO-1.44inch-LCD-Display/demo codes/c/LCD_1INCH44/build/pico-sdk/src/rp2_common/boot_stage2/bs2_default.elf" >>bs2_default.dis
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build

# Rule to build all files generated by this target.
pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\build: pico-sdk\src\rp2_common\boot_stage2\bs2_default.elf
.PHONY : pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\build

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\clean:
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build\pico-sdk\src\RP2_CO~1\BOOT_S~1
	$(CMAKE_COMMAND) -P CMakeFiles\bs2_default.dir\cmake_clean.cmake
	cd E:\lyh\products\PICO-1~1.44I\DEMOCO~1\c\LCD_1I~1\build
.PHONY : pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\clean

pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44" D:\pico-env\pico-sdk\src\rp2_common\boot_stage2 "E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44\build" "E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44\build\pico-sdk\src\rp2_common\boot_stage2" "E:\lyh\products\PICO-1.44inch-LCD-Display\demo codes\c\LCD_1INCH44\build\pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : pico-sdk\src\rp2_common\boot_stage2\CMakeFiles\bs2_default.dir\depend
