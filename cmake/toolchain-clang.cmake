set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

include(${CMAKE_CURRENT_LIST_DIR}/toolchain-gcc.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -Wno-unknown-warning-option -Wno-nan-infinity-disabled")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
