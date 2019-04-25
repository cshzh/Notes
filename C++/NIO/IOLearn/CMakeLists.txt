cmake_minimum_required(VERSION 3.13)
project(IOLearn)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server Server.cpp)
add_executable(Client Client.cpp)
add_executable(FileIO main.cpp)