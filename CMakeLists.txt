cmake_minimum_required(VERSION 3.20)
option(TERREATECORE_BUILD_TESTS "Enable test" ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined,address")
add_subdirectory(impls)

if(TERREATECORE_BUILD_TESTS)
  add_subdirectory(tests)
endif()
