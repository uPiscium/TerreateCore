cmake_minimum_required(VERSION 3.20)
project(TerreateCore)
message(STATUS "Project name: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")

function(SetIncludes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes/deps/)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes)
endfunction()

function(Build)
  add_library(${PROJECT_NAME} STATIC object.cpp executor.cpp uuid.cpp)
  set_target_properties(
    ${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
                               LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  setincludes()
endfunction()

build()
