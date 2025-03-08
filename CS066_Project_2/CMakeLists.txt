cmake_minimum_required(VERSION 3.30)
project(CS066_Project_2)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("${PROJECT_SOURCE_DIR}/assem66" "${PROJECT_SOURCE_DIR}/assem66/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/sim66" "${PROJECT_SOURCE_DIR}/sim66/cmake-build-debug")