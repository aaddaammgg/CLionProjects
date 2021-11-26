//
// Created by Adam G. on 11/2/2021.
//

#ifndef CS3A_LINKEDLIST_LINKEDLIST_CPP
#define CS3A_LINKEDLIST_LINKEDLIST_CPP

#include "LinkedList.h"

template<class T>
void LinkedList<T>::push_front(T item) {
    if (head == nullptr) {
        addFirstNode(item);
    } else {
        Node<T>* n = createNode(item);
        n->next = head;
        head = n;
    }
}

template<class T>
void LinkedList<T>::push_back(T item) {
    if (head == nullptr) {
        addFirstNode(item);
    } else {
        Node<T>* n = createNode(item);
        tail->next = n;
        tail = n;
    }
}

template<class T>
Node<T> *LinkedList<T>::createNode(T item) {
    Node<T>* n = new Node<T>;
    n->data = item;
    n->next = nullptr; // not needed already did it in Node.h L11

    return n;
}

template<class T>
void LinkedList<T>::addFirstNode(T item) {
    Node<T>* n = createNode(item);

    head = n;
    tail = n;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
    Node<T>* temp = list.head;
    while (temp != nullptr) {
        os << temp->data << " ";
        temp = temp->next;
    }

    return os;
}

#endif //CS3A_LINKEDLIST_LINKEDLIST_CPP