cmake_minimum_required(VERSION 3.20)
project(CS008_Bouncing_Objects)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS008_Bouncing_Objects main.cpp BouncingObject.cpp BouncingObject.h)

target_link_libraries(CS008_Bouncing_Objects sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)