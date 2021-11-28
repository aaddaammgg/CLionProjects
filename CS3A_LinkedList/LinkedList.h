//
// Created by Adam G. on 11/2/2021.
//

#ifndef CS3A_LINKEDLIST_LINKEDLIST_H
#define CS3A_LINKEDLIST_LINKEDLIST_H

#include <ostream>
#include "Node.h"
#include <iostream>

template <class T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    void addFirstNode(T item);
    Node<T>* createNode(T item);

    int size = 0;
    void subSize();
public:
    LinkedList();
    ~LinkedList<T>();

    void push_front(T item);
    void push_back(T item);

    void pop_front();
    void pop_back();

    Node<T>* front();
    Node<T>* back();

    int getSize();

    template <class S>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<S>& list);

};

#include "LinkedList.cpp"

#endif //CS3A_LINKEDLIST_LINKEDLIST_H
