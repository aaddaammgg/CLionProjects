//
// Created by Adam G. on 2/2/22.
//

#ifndef CS008_DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define CS008_DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>
#include <ostream>
#include "Node.h"
#include "Node_Iterator.h"

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    void addFirstNode(T item);
    Node<T>* createNode(T item);
    Node<T>* search(T item);
    void insertBefore(T newItem, Node<T>* before);
    void insertAfter(T newItem, Node<T>* after);
    void remove(Node<T>* node);
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& list); // copy constructor
    ~DoublyLinkedList(); // destructor

    typedef Node_Iterator<T> iterator;
    iterator begin();
    iterator end();

    bool isEmpty();
    int getSize();
    void remove(T item);

    T& front();
    T& back();

    void pop_front();
    void pop_back();

    void push_front(T item);
    void push_back(T item);

    void insertBefore(T newItem, T before);
    void insertAfter(T newItem, T after);

    template <class S>
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<S>& list);
    DoublyLinkedList<T>& operator=( const DoublyLinkedList& rhs );
    void operator+=(const T& item);
};

#include "DoublyLinkedList.cpp"

#endif //CS008_DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
