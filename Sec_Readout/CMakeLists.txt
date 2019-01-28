cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(readout)

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/share/include
                    ${Geant4_INCLUDE_DIR})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc
                  ${PROJECT_SOURCE_DIR}/share/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh
                  ${PROJECT_SOURCE_DIR}/share/include/*.hh)

add_executable(readout readout.cc ${sources} ${headers})
target_link_libraries(readout ${Geant4_LIBRARIES})

set(READOUT_SCRIPTS
  #readout.out
  #exampleB2.in
  #gui.mac
  #run1.mac
  #run2.mac
  init_vis.mac
  vis.mac
  )

  foreach(_script ${READOUT_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

install(TARGETS readout DESTINATION bin)
