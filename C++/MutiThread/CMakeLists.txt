cmake_minimum_required(VERSION 3.14)
project(MutiThread)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -O3")

add_executable(MutiThread main.cpp)
target_link_libraries(MutiThread pthread)