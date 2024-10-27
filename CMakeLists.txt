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
add_executable(BMP.EXE EXMPLSRC/BMP.CPP)
add_executable(GUN.EXE EXMPLSRC/GUN.CPP)
add_executable(IMAGE.EXE EXMPLSRC/IMAGE.CPP)
add_executable(MACHINE.EXE EXMPLSRC/MACHINE.CPP)
add_executable(MORPH.EXE EXMPLSRC/MORPH.CPP)
add_executable(SPHERE.EXE EXMPLSRC/SPHERE.CPP)
add_executable(SURFACES.EXE EXMPLSRC/SURFACES.CPP)
add_executable(TEX.EXE EXMPLSRC/TEX.CPP)
add_executable(TEXFACES.EXE EXMPLSRC/TEXFACES.CPP)
add_executable(TRI.EXE EXMPLSRC/TRI.CPP)
add_executable(ZBT.EXE EXMPLSRC/ZBT.CPP)
