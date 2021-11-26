//
// Created by Adam G. on 11/2/2021.
//

#ifndef CS3A_LINKEDLIST_NODE_H
#define CS3A_LINKEDLIST_NODE_H

template <class T>
struct Node {
    T data;
    Node<T>* next = nullptr;
};

#endif //CS3A_LINKEDLIST_NODE_H
