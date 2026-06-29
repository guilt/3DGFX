cmake_minimum_required(VERSION 3.5)
project(3DGFX)

# Output Directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/EXAMPLES/")

# Include Directories
include_directories(
    ${PROJECT_SOURCE_DIR}/INCLUDE/
)

# C++ Standard
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform detection
if(WIN32 OR MINGW)
    add_definitions(-DWIN)
    if(MSVC)
        set(PLATFORM_LIBS gdi32.lib user32.lib)
    else()
        set(PLATFORM_LIBS -lgdi32 -luser32)
    endif()
endif()

# Debug mode (BUILD.BAT DEBUG=1 equivalent)
option(DEBUG "Enable debug logging (-DDEBUG)" OFF)
if(DEBUG)
    add_definitions(-DDEBUG)
endif()

# --- All 12 examples ---

add_executable(BMP  EXMPLSRC/BMP.CPP)
add_executable(GUN  EXMPLSRC/GUN.CPP)
add_executable(IMAGE EXMPLSRC/IMAGE.CPP)
add_executable(MACHINE EXMPLSRC/MACHINE.CPP)
add_executable(MORPH EXMPLSRC/MORPH.CPP)
add_executable(SPHERE EXMPLSRC/SPHERE.CPP)
add_executable(SURFACES EXMPLSRC/SURFACES.CPP)
add_executable(TEX  EXMPLSRC/TEX.CPP)
add_executable(TEXFACES EXMPLSRC/TEXFACES.CPP)
add_executable(TEXT  EXMPLSRC/TEXT.CPP)
add_executable(TRI  EXMPLSRC/TRI.CPP)
add_executable(ZBT  EXMPLSRC/ZBT.CPP)

# ZBT defines IHSR/ITEX/IZBUF/IZCLIP at top of source -- no extra -D needed

if(PLATFORM_LIBS)
    target_link_libraries(BMP  ${PLATFORM_LIBS})
    target_link_libraries(GUN  ${PLATFORM_LIBS})
    target_link_libraries(IMAGE ${PLATFORM_LIBS})
    target_link_libraries(MACHINE ${PLATFORM_LIBS})
    target_link_libraries(MORPH ${PLATFORM_LIBS})
    target_link_libraries(SPHERE ${PLATFORM_LIBS})
    target_link_libraries(SURFACES ${PLATFORM_LIBS})
    target_link_libraries(TEX  ${PLATFORM_LIBS})
    target_link_libraries(TEXFACES ${PLATFORM_LIBS})
    target_link_libraries(TEXT  ${PLATFORM_LIBS})
    target_link_libraries(TRI  ${PLATFORM_LIBS})
    target_link_libraries(ZBT  ${PLATFORM_LIBS})
endif()
