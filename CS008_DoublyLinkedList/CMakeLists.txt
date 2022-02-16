cmake_minimum_required(VERSION 3.20)
project(CS008_DoublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS008_DoublyLinkedList main.cpp DoublyLinkedList.cpp DoublyLinkedList.h Node.h Node_Iterator.cpp Node_Iterator.h)
