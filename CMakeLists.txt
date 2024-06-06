cmake_minimum_required(VERSION 3.20.0)
project(HirttoUkkoPeli)
add_executable(HirttoUkkoPeli main.cpp game.cpp hangmanui.hpp hangmanui.cpp)
add_executable(test test.cpp game.cpp hangmanui.hpp hangmanui.cpp)
