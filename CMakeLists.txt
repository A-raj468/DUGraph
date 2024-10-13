cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 14 CACHE STRING "")
project(duedges)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Load LLVMConfig.cmake. If this fails, consider setting `LLVM_HOME` to point
# to your LLVM installation's home directory.
if(NOT DEFINED ENV{LLVM_HOME})
    message(WARNING "$LLVM_HOME is not defined, using /usr/lib/llvm-14 as LLVM_HOME")
    set(ENV{LLVM_HOME} /usr/lib/llvm-14)
endif()

set(ENV{LLVM_DIR} $ENV{LLVM_HOME}/lib/cmake/llvm)

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
include(AddLLVM)

# LLVM is normally built without RTTI. Be consistent with that.
if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

# Our pass lives in this subdirectory.
add_subdirectory(lib)
add_subdirectory(test)

