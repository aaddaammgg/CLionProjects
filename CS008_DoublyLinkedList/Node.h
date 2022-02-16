//
// Created by Adam G. on 2/2/22.
//

#ifndef CS008_DOUBLYLINKEDLIST_NODE_H
#define CS008_DOUBLYLINKEDLIST_NODE_H

template <class T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

#endif //CS008_DOUBLYLINKEDLIST_NODE_H
