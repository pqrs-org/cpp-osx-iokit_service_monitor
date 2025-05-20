cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-O2)

project (example)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
include_directories(SYSTEM ${CMAKE_CURRENT_LIST_DIR}/../vendor/vendor/include)

add_executable(
  example
  main.cpp
)

target_link_libraries(
  example
  "-framework CoreFoundation"
  "-framework IOKit"
)
