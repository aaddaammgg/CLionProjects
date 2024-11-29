cmake_minimum_required(VERSION 3.30)
project(BTree_Jacob)

set(CMAKE_CXX_STANDARD 20)

add_executable(BTree_Jacob main.cpp
        BTree.cpp
        BTree.h
        BTreeNode.cpp
        BTreeNode.h)
