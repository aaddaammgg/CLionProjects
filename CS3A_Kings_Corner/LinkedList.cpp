//
// Created by Adam G. on 11/2/2021.
//

#ifndef CS3A_LINKEDLIST_LINKEDLIST_CPP
#define CS3A_LINKEDLIST_LINKEDLIST_CPP

#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() {

}

template<class T>
LinkedList<T>::~LinkedList<T>() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        Node<T>* next_ = temp->next;
        delete temp;
        temp = next_;
    }
    head = nullptr;
}

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
void LinkedList<T>::pop_front() {
    subSize();

    if (head == nullptr) {
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template<class T>
void LinkedList<T>::pop_back() {
    subSize();

    if (head == nullptr) {
        return;
    } else if (head->next == nullptr) {
        delete tail;
        head = nullptr;
    } else {
        Node<T>* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        tail = secondLast;
        delete tail->next;
        tail->next = nullptr;
    }

}

template<class T>
Node<T> *LinkedList<T>::front() {
    return head;
}

template<class T>
Node<T> *LinkedList<T>::back() {
    return tail;
}

template<class T>
Node<T> *LinkedList<T>::createNode(T item) {
    size++;
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
void LinkedList<T>::subSize() {
    --size;
    if (size < 0) {
        size = 0;
    }
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

#endif //CS3A_LINKEDLIST_LINKEDLIST_CPP