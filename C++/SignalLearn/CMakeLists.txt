cmake_minimum_required(VERSION 3.13)
project(SignalLearn)

set(CMAKE_CXX_STANDARD 14)

add_library(csapp SHARED csapp.c)
add_executable(SignalLearn main.cpp )
target_link_libraries(SignalLearn csapp)
target_link_libraries(SignalLearn pthread)