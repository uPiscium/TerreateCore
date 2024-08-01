cmake_minimum_required(VERSION 3.20)
option(TERREATECORE_BUILD_TESTS "Enable test" ON)

add_subdirectory(impls)

if(ENABLE_TESTS)
  add_subdirectory(tests)
endif()
