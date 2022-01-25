# define the version of Cmake which is minimun to run the program
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)


# define the name of our project
project(NaInew)


# find which kernel is neccesary to compile
find_package(Geant4 REQUIRED ui_all vis_all)

# tell cmake which kinda files are in this project
include(${Geant4_USE_FILE})

file(GLOB MACRO_FILES
    "*.mac"
)

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR}
    
)

# compile the file of the project
file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

# create the executable
add_executable(naidetector naidetector.cc ${sources} ${headers})
# add necessary libreries to compile geant4
target_link_libraries(naidetector ${Geant4_LIBRARIES})

add_custom_target(NaInew DEPENDS naidetector)

foreach(_script ${EXAMPLEB3_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

