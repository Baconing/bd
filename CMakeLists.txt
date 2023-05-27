cmake_minimum_required(VERSION 3.25)
project(bacondb)

set(CMAKE_CXX_STANDARD 17)

add_executable(bacondb src/main.cpp src/language/Lexer.cpp src/language/Lexer.h src/language/Token.h)
