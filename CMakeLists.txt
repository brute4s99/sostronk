cmake_minimum_required (VERSION 3.0)

project (matchmaking)

add_subdirectory (src)

set(CMAKE_AUTOMOC ON)

enable_testing ()
add_subdirectory (test)
