cmake_minimum_required(VERSION 3.20)
project(inheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(inheritance main.cpp Person.cpp Person.h Student.cpp Student.h)
