cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-O2)

project(example LANGUAGES CXX OBJC)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
include_directories(SYSTEM ${CMAKE_CURRENT_LIST_DIR}/../vendor/vendor/include)

set(AUTORELEASE_POOL_IMPL
  ${CMAKE_CURRENT_LIST_DIR}/../vendor/vendor/src/pqrs/osx/autorelease_pool/PQRSOSXAutoreleasePoolImpl.m
)

set_source_files_properties(
  ${AUTORELEASE_POOL_IMPL}
  PROPERTIES
  COMPILE_OPTIONS -fno-objc-arc
)

add_executable(
  example
  main.cpp
  ${AUTORELEASE_POOL_IMPL}
)

target_link_libraries(
  example
  "-framework CoreFoundation"
  "-framework Foundation"
  "-framework IOKit"
)
