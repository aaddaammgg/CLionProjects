cmake_minimum_required(VERSION 3.20)
project(sfmlTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(sfmlTest main.cpp)
target_link_libraries(sfmlTest sfml-graphics sfml-audio)

find_package(SFML COMPONENTS graphics audio REQUIRED)