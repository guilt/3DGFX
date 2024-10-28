cmake_minimum_required(VERSION 3.5)

# Project Name
project(3DGFX)

# Output Directory
set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/EXAMPLES/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Include Directories
include_directories(
    ${PROJECT_SOURCE_DIR}/BGI/
    ${PROJECT_SOURCE_DIR}/INCLUDE/
    ${PROJECT_SOURCE_DIR}/EINCLUDE/
)

# CMake C++ Standard
set(CMAKE_CXX_STANDARD 98)

# Excecutables
add_executable(BMP EXMPLSRC/BMP.CPP)
add_executable(GUN EXMPLSRC/GUN.CPP)
add_executable(IMAGE EXMPLSRC/IMAGE.CPP)
add_executable(MACHINE EXMPLSRC/MACHINE.CPP)
add_executable(MORPH EXMPLSRC/MORPH.CPP)
add_executable(SPHERE EXMPLSRC/SPHERE.CPP)
add_executable(SURFACES EXMPLSRC/SURFACES.CPP)
add_executable(TEX EXMPLSRC/TEX.CPP)
add_executable(TEXFACES EXMPLSRC/TEXFACES.CPP)
add_executable(TRI EXMPLSRC/TRI.CPP)
add_executable(ZBT EXMPLSRC/ZBT.CPP)
