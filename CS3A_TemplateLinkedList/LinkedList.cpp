//
// Created by Adam G. on 11/10/2021.
//

#ifndef CS3A_TEMPLATELINKEDLIST_LINKEDLIST_CPP
#define CS3A_TEMPLATELINKEDLIST_LINKEDLIST_CPP

#include "LinkedList.h"

template<class T>
void LinkedList<T>::push_front(T item) {
    if (head == nullptr) {
        addFirstNode(item);
    } else {
        Node<T>* n = createNode(item);
        n->next = head;
        head->prev = n;
        head = n;
    }
}

template<class T>
void LinkedList<T>::push_back(T item) {
    if (head == nullptr) {
        addFirstNode(item);
    } else {
        Node<T>* n = createNode(item);
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
int LinkedList<T>::getSize() {
    int counter = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        counter++;
    }

    return counter;
}

template<class T>
void LinkedList<T>::insertBefore(T newItem, T item) {
    Node<T>* selectedNode = this->findItem(item);

    if (selectedNode == nullptr) {
        return;
    }

    Node<T>* newNode = createNode(newItem);
    newNode->prev = selectedNode->prev;
    selectedNode->prev = newNode;
    newNode->next = selectedNode;

    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    } else {
        head = newNode;
    }
}

template<class T>
void LinkedList<T>::insertAfter(T newItem, T item) {
    Node<T>* selectedNode = this->findItem(item);

    if (selectedNode == nullptr) {
        return;
    }

    Node<T>* newNode = createNode(newItem);
    newNode->next = selectedNode->next;
    selectedNode->next = newNode;
    newNode->prev = selectedNode;

    if (newNode->prev != nullptr)
        newNode->prev->next = newNode;
}

template<class T>
Node<T> *LinkedList<T>::findItem(T item) {
    Node<T>* n = head;
    while(n != nullptr) {
        if (n->data == item)
            return n;
        n = n->next;
    }
    return nullptr;
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

template<class T>
void LinkedList<T>::operator+=(const T& item) {
    push_back(item);
}

#endif //CS3A_TEMPLATELINKEDLIST_LINKEDLIST_CPP