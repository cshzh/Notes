cmake_minimum_required(VERSION 3.14)
project(RedisDemo)

set(CMAKE_CXX_STANDARD 11)

add_executable(RedisDemo main.cpp)
target_link_libraries(RedisDemo cpp_redis tacopie pthread)