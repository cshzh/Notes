cmake_minimum_required(VERSION 3.13)
project(EpollLearn)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server Server.cpp Server.h)
target_link_libraries(Server csapp)
target_link_libraries(Server pthread)

add_executable(Client Client.cpp Client.h)
target_link_libraries(Client csapp)
target_link_libraries(Client pthread)