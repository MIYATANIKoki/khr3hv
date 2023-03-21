if(MSVC)
  # Version 3.13 or later is required because the following features are used in this project.
  # * CMAKE_CXX_STANDARD 17 is supported for MSVC since version 3.10
  # * The target_link_options command is available since version 3.13
  # * The install command can specifiy a target defined in a sub directory since version 3.13
  cmake_minimum_required(VERSION 3.13)
else()
  # CMake version 3.5.1 is installed in Ubuntu 16.04.
  # (Version 3.10.2 is installed in Ubuntu 18.04.)
  cmake_minimum_required(VERSION 3.5)
endif()

project(com_test)
 
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/base.cmake")

include_directories("${CMAKE_SOURCE_DIR}/dll")
add_library(com_test_dll Extensions.dll Rcb4.dll)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src/com_test)
 
target_link_libraries(com_test com_test_dll)