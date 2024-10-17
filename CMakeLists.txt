cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14 CACHE STRING "")
project(duedges)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Set the build type" FORCE)
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;MinSizeRel" CACHE STRING "Available build types" FORCE)

add_subdirectory(src)
add_subdirectory(test)
