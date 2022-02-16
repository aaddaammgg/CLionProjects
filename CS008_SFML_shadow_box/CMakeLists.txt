cmake_minimum_required(VERSION 3.20)
project(sfml_shadow_box)

set(CMAKE_CXX_STANDARD 14)

add_executable(sfml_shadow_box main.cpp TextReflection.cpp TextReflection.h ResourceHolder.cpp ResourceHolder.h)
target_link_libraries(sfml_shadow_box sfml-graphics sfml-audio)

find_package(SFML COMPONENTS graphics audio REQUIRED)