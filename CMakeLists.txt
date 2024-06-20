cmake_minimum_required (VERSION 3.28 FATAL_ERROR)

project (advent23)

MESSAGE(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

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

# CPM libraries
include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#10.2.1")
list(APPEND LIBRARIES fmt::fmt)

CPMAddPackage("gh:tcbrindle/flux#main")
list(APPEND LIBRARIES flux::flux)

CPMAddPackage(
  NAME Boost
  VERSION 1.85.0
  URL https://github.com/boostorg/boost/releases/download/boost-1.85.0/boost-1.85.0-cmake.tar.gz
  URL_HASH SHA256=ab9c9c4797384b0949dd676cf86b4f99553f8c148d767485aaac412af25183e6
  OPTIONS "BOOST_ENABLE_CMAKE ON" "BOOST_INCLUDE_LIBRARIES icl"
)
list(APPEND LIBRARIES Boost::icl)

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
target_link_libraries(advent23 PRIVATE ${LIBRARIES})
