cmake_minimum_required(VERSION 3.13)
project(PollLearn)

set(CMAKE_CXX_STANDARD 14)

add_executable(PollLearn main.cpp)

add_executable(Server Server.cpp Server.h)
target_link_libraries(Server csapp)
target_link_libraries(Server pthread)

add_executable(Client Client.cpp Client.h)
target_link_libraries(Client csapp)
target_link_libraries(Client pthread)

add_executable(Main main.cpp)