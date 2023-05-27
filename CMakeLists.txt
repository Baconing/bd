cmake_minimum_required(VERSION 3.25)
project(bacondb)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

add_executable(bacondb ${SOURCES})