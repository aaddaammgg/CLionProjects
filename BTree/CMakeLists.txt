cmake_minimum_required(VERSION 3.27)
project(BTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(BTree main.cpp
        BTree.cpp
        BTree.h
        BTreeNode.cpp
        BTreeNode.h)
