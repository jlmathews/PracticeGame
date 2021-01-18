cmake_minimum_required(VERSION 3.10)
project(PracticeGames LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

message(STATUS "Is the C++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")
if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
  message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()

include_directories(src)

find_path(HIREDIS_HEADER hiredis)
message(STATUS "HIREDIS_HEADER: ${HIREDIS_HEADER}")

find_library(HIREDIS_LIB hiredis)
message(STATUS "HIREDIS_LIB: ${HIREDIS_LIB}")

find_path(REDIS_PLUS_PLUS_HEADER sw)
message(STATUS "REDIS_PLUS_PLUS_HEADER: ${REDIS_PLUS_PLUS_HEADER}")

find_library(REDIS_PLUS_PLUS_LIB redis++)
message(STATUS "REDIS_PLUS_PLUS_LIB: ${REDIS_PLUS_PLUS_LIB}")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
add_subdirectory(lib/sol2)
add_subdirectory(lib/spdlog)
add_subdirectory(lib/stduuid)

add_subdirectory(docs)
