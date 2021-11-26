//
// Created by Adam G. on 11/10/2021.
//

#ifndef CS3A_TEMPLATELINKEDLIST_NODE_H
#define CS3A_TEMPLATELINKEDLIST_NODE_H

template <class T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

#endif //CS3A_TEMPLATELINKEDLIST_NODE_H
