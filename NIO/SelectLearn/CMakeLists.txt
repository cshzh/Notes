cmake_minimum_required(VERSION 3.13)
project(SelectLearn)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server server.cpp)
add_executable(Client client.cpp)