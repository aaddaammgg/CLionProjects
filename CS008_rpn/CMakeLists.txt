cmake_minimum_required(VERSION 3.20)
project(rpn)

set(CMAKE_CXX_STANDARD 14)

add_executable(rpn main.cpp RPN.cpp RPN.h)
