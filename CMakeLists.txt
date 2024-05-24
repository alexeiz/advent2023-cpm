cmake_minimum_required (VERSION 3.29 FATAL_ERROR)

project (advent23)

# set build type
set(default_build_type "Debug")
if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to '${default_build_type}'")

  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose build type." FORCE)

  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
      STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

# set compiler flags
set(CMAKE_CXX_STANDARD   23)
set(CMAKE_CXX_EXTENSIONS OFF)
string(REPLACE "-std=c++11" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wunused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wduplicated-cond -Wlogical-op")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wrestrict -Wnull-dereference")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffast-math")

# Clang-specific
if (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -Wno-unknown-warning-option")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
endif ()

# CPM libraries
include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#10.2.1")
list(APPEND LIBRARIES fmt)

# include directories and source files
include_directories(include)
set(SOURCES
    src/main.cpp
    src/day01_1.cpp src/day01_2.cpp
    src/day02_1.cpp src/day02_2.cpp
    src/day03_1.cpp src/day03_2.cpp
    src/day04_1.cpp src/day04_2.cpp
    src/day05_1.cpp src/day05_2.cpp
    src/day06_1.cpp src/day06_2.cpp
    src/day11_1.cpp src/day11_2.cpp
    src/day12.cpp)

# executable
add_executable(advent23 ${SOURCES})
target_link_libraries(advent23 ${LIBRARIES})
