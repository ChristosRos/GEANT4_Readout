# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/christos/GEANT4/PCB_Readout

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/christos/GEANT4/PCB_Readout/build

# Include any dependencies generated for this target.
include CMakeFiles/Readout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Readout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Readout.dir/flags.make

CMakeFiles/Readout.dir/Readout.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/Readout.cc.o: ../Readout.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Readout.dir/Readout.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/Readout.cc.o -c /Users/christos/GEANT4/PCB_Readout/Readout.cc

CMakeFiles/Readout.dir/Readout.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/Readout.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/Readout.cc > CMakeFiles/Readout.dir/Readout.cc.i

CMakeFiles/Readout.dir/Readout.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/Readout.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/Readout.cc -o CMakeFiles/Readout.dir/Readout.cc.s

CMakeFiles/Readout.dir/src/DetectorConstruction.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/DetectorConstruction.cc.o: ../src/DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Readout.dir/src/DetectorConstruction.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/DetectorConstruction.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/DetectorConstruction.cc

CMakeFiles/Readout.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/DetectorConstruction.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/DetectorConstruction.cc > CMakeFiles/Readout.dir/src/DetectorConstruction.cc.i

CMakeFiles/Readout.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/DetectorConstruction.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/DetectorConstruction.cc -o CMakeFiles/Readout.dir/src/DetectorConstruction.cc.s

CMakeFiles/Readout.dir/src/DetectorHit.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/DetectorHit.cc.o: ../src/DetectorHit.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Readout.dir/src/DetectorHit.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/DetectorHit.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/DetectorHit.cc

CMakeFiles/Readout.dir/src/DetectorHit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/DetectorHit.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/DetectorHit.cc > CMakeFiles/Readout.dir/src/DetectorHit.cc.i

CMakeFiles/Readout.dir/src/DetectorHit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/DetectorHit.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/DetectorHit.cc -o CMakeFiles/Readout.dir/src/DetectorHit.cc.s

CMakeFiles/Readout.dir/src/DetectorRun.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/DetectorRun.cc.o: ../src/DetectorRun.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Readout.dir/src/DetectorRun.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/DetectorRun.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/DetectorRun.cc

CMakeFiles/Readout.dir/src/DetectorRun.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/DetectorRun.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/DetectorRun.cc > CMakeFiles/Readout.dir/src/DetectorRun.cc.i

CMakeFiles/Readout.dir/src/DetectorRun.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/DetectorRun.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/DetectorRun.cc -o CMakeFiles/Readout.dir/src/DetectorRun.cc.s

CMakeFiles/Readout.dir/src/DetectorStrip.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/DetectorStrip.cc.o: ../src/DetectorStrip.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Readout.dir/src/DetectorStrip.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/DetectorStrip.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/DetectorStrip.cc

CMakeFiles/Readout.dir/src/DetectorStrip.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/DetectorStrip.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/DetectorStrip.cc > CMakeFiles/Readout.dir/src/DetectorStrip.cc.i

CMakeFiles/Readout.dir/src/DetectorStrip.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/DetectorStrip.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/DetectorStrip.cc -o CMakeFiles/Readout.dir/src/DetectorStrip.cc.s

CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.o: ../src/PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/PrimaryGeneratorAction.cc

CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/PrimaryGeneratorAction.cc > CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.i

CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/PrimaryGeneratorAction.cc -o CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.s

CMakeFiles/Readout.dir/src/RootWriter.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/RootWriter.cc.o: ../src/RootWriter.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Readout.dir/src/RootWriter.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/RootWriter.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/RootWriter.cc

CMakeFiles/Readout.dir/src/RootWriter.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/RootWriter.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/RootWriter.cc > CMakeFiles/Readout.dir/src/RootWriter.cc.i

CMakeFiles/Readout.dir/src/RootWriter.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/RootWriter.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/RootWriter.cc -o CMakeFiles/Readout.dir/src/RootWriter.cc.s

CMakeFiles/Readout.dir/src/RunAction.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/RunAction.cc.o: ../src/RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Readout.dir/src/RunAction.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/RunAction.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/RunAction.cc

CMakeFiles/Readout.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/RunAction.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/RunAction.cc > CMakeFiles/Readout.dir/src/RunAction.cc.i

CMakeFiles/Readout.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/RunAction.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/RunAction.cc -o CMakeFiles/Readout.dir/src/RunAction.cc.s

CMakeFiles/Readout.dir/src/SensitiveDetector.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/SensitiveDetector.cc.o: ../src/SensitiveDetector.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Readout.dir/src/SensitiveDetector.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/SensitiveDetector.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/SensitiveDetector.cc

CMakeFiles/Readout.dir/src/SensitiveDetector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/SensitiveDetector.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/SensitiveDetector.cc > CMakeFiles/Readout.dir/src/SensitiveDetector.cc.i

CMakeFiles/Readout.dir/src/SensitiveDetector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/SensitiveDetector.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/SensitiveDetector.cc -o CMakeFiles/Readout.dir/src/SensitiveDetector.cc.s

CMakeFiles/Readout.dir/src/SteppingAction.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/SteppingAction.cc.o: ../src/SteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Readout.dir/src/SteppingAction.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/SteppingAction.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/SteppingAction.cc

CMakeFiles/Readout.dir/src/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/SteppingAction.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/SteppingAction.cc > CMakeFiles/Readout.dir/src/SteppingAction.cc.i

CMakeFiles/Readout.dir/src/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/SteppingAction.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/SteppingAction.cc -o CMakeFiles/Readout.dir/src/SteppingAction.cc.s

CMakeFiles/Readout.dir/src/TrackingAction.cc.o: CMakeFiles/Readout.dir/flags.make
CMakeFiles/Readout.dir/src/TrackingAction.cc.o: ../src/TrackingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Readout.dir/src/TrackingAction.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readout.dir/src/TrackingAction.cc.o -c /Users/christos/GEANT4/PCB_Readout/src/TrackingAction.cc

CMakeFiles/Readout.dir/src/TrackingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readout.dir/src/TrackingAction.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christos/GEANT4/PCB_Readout/src/TrackingAction.cc > CMakeFiles/Readout.dir/src/TrackingAction.cc.i

CMakeFiles/Readout.dir/src/TrackingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readout.dir/src/TrackingAction.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christos/GEANT4/PCB_Readout/src/TrackingAction.cc -o CMakeFiles/Readout.dir/src/TrackingAction.cc.s

# Object files for target Readout
Readout_OBJECTS = \
"CMakeFiles/Readout.dir/Readout.cc.o" \
"CMakeFiles/Readout.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/Readout.dir/src/DetectorHit.cc.o" \
"CMakeFiles/Readout.dir/src/DetectorRun.cc.o" \
"CMakeFiles/Readout.dir/src/DetectorStrip.cc.o" \
"CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/Readout.dir/src/RootWriter.cc.o" \
"CMakeFiles/Readout.dir/src/RunAction.cc.o" \
"CMakeFiles/Readout.dir/src/SensitiveDetector.cc.o" \
"CMakeFiles/Readout.dir/src/SteppingAction.cc.o" \
"CMakeFiles/Readout.dir/src/TrackingAction.cc.o"

# External object files for target Readout
Readout_EXTERNAL_OBJECTS =

Readout: CMakeFiles/Readout.dir/Readout.cc.o
Readout: CMakeFiles/Readout.dir/src/DetectorConstruction.cc.o
Readout: CMakeFiles/Readout.dir/src/DetectorHit.cc.o
Readout: CMakeFiles/Readout.dir/src/DetectorRun.cc.o
Readout: CMakeFiles/Readout.dir/src/DetectorStrip.cc.o
Readout: CMakeFiles/Readout.dir/src/PrimaryGeneratorAction.cc.o
Readout: CMakeFiles/Readout.dir/src/RootWriter.cc.o
Readout: CMakeFiles/Readout.dir/src/RunAction.cc.o
Readout: CMakeFiles/Readout.dir/src/SensitiveDetector.cc.o
Readout: CMakeFiles/Readout.dir/src/SteppingAction.cc.o
Readout: CMakeFiles/Readout.dir/src/TrackingAction.cc.o
Readout: CMakeFiles/Readout.dir/build.make
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4Tree.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4GMocren.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4visHepRep.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4RayTracer.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4VRML.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4OpenGL.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4gl2ps.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4interfaces.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4persistency.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4analysis.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4error_propagation.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4readout.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4physicslists.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4parmodels.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4FR.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4vis_management.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4modeling.dylib
Readout: /opt/local/lib/libXm.dylib
Readout: /opt/local/lib/libSM.dylib
Readout: /opt/local/lib/libICE.dylib
Readout: /opt/local/lib/libX11.dylib
Readout: /opt/local/lib/libXext.dylib
Readout: /opt/local/lib/libXt.dylib
Readout: /opt/local/lib/libXmu.dylib
Readout: /opt/local/lib/libGL.dylib
Readout: /opt/local/lib/libGLU.dylib
Readout: /opt/local/libexec/qt5/lib/QtOpenGL.framework/QtOpenGL
Readout: /opt/local/libexec/qt5/lib/QtPrintSupport.framework/QtPrintSupport
Readout: /opt/local/libexec/qt5/lib/QtWidgets.framework/QtWidgets
Readout: /opt/local/libexec/qt5/lib/QtGui.framework/QtGui
Readout: /opt/local/libexec/qt5/lib/QtCore.framework/QtCore
Readout: /opt/local/lib/libxerces-c.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4run.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4event.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4tracking.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4processes.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4zlib.dylib
Readout: /opt/local/lib/libexpat.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4digits_hits.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4track.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4particles.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4geometry.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4materials.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4graphics_reps.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4intercoms.dylib
Readout: /opt/local/lib/Geant4/Geant4.10.3/libG4global.dylib
Readout: /opt/local/lib/libCLHEP.dylib
Readout: CMakeFiles/Readout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/christos/GEANT4/PCB_Readout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Readout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Readout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Readout.dir/build: Readout

.PHONY : CMakeFiles/Readout.dir/build

CMakeFiles/Readout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Readout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Readout.dir/clean

CMakeFiles/Readout.dir/depend:
	cd /Users/christos/GEANT4/PCB_Readout/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/christos/GEANT4/PCB_Readout /Users/christos/GEANT4/PCB_Readout /Users/christos/GEANT4/PCB_Readout/build /Users/christos/GEANT4/PCB_Readout/build /Users/christos/GEANT4/PCB_Readout/build/CMakeFiles/Readout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Readout.dir/depend

