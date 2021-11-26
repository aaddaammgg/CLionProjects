//
// Created by Adam G. on 11/10/2021.
//

#ifndef CS3A_TEMPLATELINKEDLIST_LINKEDLIST_H
#define CS3A_TEMPLATELINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <ostream>
#include "Node.h"

template <class T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    void addFirstNode(T item);
    Node<T>* createNode(T item);

public:
    void push_front(T item);
    void push_back(T item);
    Node<T>* findItem(T item);
    bool isEmpty();
    int getSize();

    void insertBefore(T newItem, T item);
    void insertAfter(T newItem, T item);

    template <class S>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<S>& list);

    void operator+=(const T& item);
};

#include "LinkedList.cpp"


#endif //CS3A_TEMPLATELINKEDLIST_LINKEDLIST_H
