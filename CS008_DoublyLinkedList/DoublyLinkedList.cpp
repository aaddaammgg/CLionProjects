//
// Created by Adam G. on 2/2/22.
//

#ifndef CS008_DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_CPP
#define CS008_DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_CPP

#include "DoublyLinkedList.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {

}

template<class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return iterator(head);
}

template<class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
    return iterator(tail);
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &list) {
    if (list.head == nullptr) {
        head = nullptr;
        tail = nullptr;
        return;
    }

    head = createNode(list.head->data);
    Node<T>* headsNext = list.head->next;
    Node<T>* temp = head;

    while (headsNext != nullptr ) {
        temp->next = createNode(headsNext->data);
        temp->next->prev = temp;
        temp->next->next = nullptr;

        temp = temp->next;
        headsNext = headsNext->next;
    }
    tail = temp;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    Node<T>* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
void DoublyLinkedList<T>::pop_front() {
    if (isEmpty()) {
        return;
    }

//    if (head->next != nullptr) {
//        head->next->prev = nullptr;
//    }
//
//    Node<T>* temp = head->next;
//    delete head;
//    head = temp;

    Node<T>* headsNext = head->next;
    remove(head);
    head = headsNext;
}

template<class T>
void DoublyLinkedList<T>::pop_back() {
    if (isEmpty()) {
        return;
    }

//    if (tail->prev != nullptr) {
//        tail->prev->next = nullptr;
//    }
//
//    Node<T>* temp = tail->prev;
//    delete tail;
//    tail = temp;

    Node<T>* tailsPrev = tail->prev;
    remove(tail);
    tail = tailsPrev;
}

template<class T>
void DoublyLinkedList<T>::push_front(T item) {
    if (isEmpty()) {
        addFirstNode(item);
    } else {
        Node<T>* n = createNode(item);
        n->next = head;
        head->prev = n;
        head = n;
    }
}

template<class T>
void DoublyLinkedList<T>::push_back(T item) {
    if (isEmpty()) {
        addFirstNode(item);
    } else {
        Node<T>* n = createNode(item);
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
int DoublyLinkedList<T>::getSize() {
    if (isEmpty()) {
        return 0;
    }

    int counter = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        counter++;
    }

    return counter;
}

template<class T>
void DoublyLinkedList<T>::remove(T item) {
    remove(search(item));
}

template<class T>
void DoublyLinkedList<T>::insertBefore(T newItem, Node<T> *before) {
    if (isEmpty() || before == nullptr) {
        return;
    }

    Node<T>* newNode = createNode(newItem);
    newNode->prev = before->prev;
    before->prev = newNode;
    newNode->next = before;

    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    } else {
        head = newNode;
    }
}

template<class T>
void DoublyLinkedList<T>::insertAfter(T newItem, Node<T> *after) {
    if (isEmpty() || after == nullptr) {
        return;
    }

    Node<T>* newNode = createNode(newItem);
    newNode->next = after->next;
    after->next = newNode;
    newNode->prev = after;

    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    }
}

template<class T>
void DoublyLinkedList<T>::insertBefore(T newItem, T before) {
    Node<T>* selectedNode = this->search(before);
    insertBefore(newItem, selectedNode);
}

template<class T>
void DoublyLinkedList<T>::insertAfter(T newItem, T after) {
    Node<T>* selectedNode = this->search(after);
    insertAfter(newItem, selectedNode);
}

template<class T>
T &DoublyLinkedList<T>::front() {
    return head->data;
}

template<class T>
T &DoublyLinkedList<T>::back() {
    return tail->data;
}

template<class T>
Node<T>* DoublyLinkedList<T>::search(T item) {
    if (isEmpty()) {
        return nullptr;
    }

    Node<T>* n = head;
    while(n != nullptr) {
        if (n->data == item) {
            return n;
        }
        n = n->next;
    }
    return nullptr;
}

template<class T>
Node<T>* DoublyLinkedList<T>::createNode(T item) {
    Node<T>* n = new Node<T>;
    n->data = item;

    return n;
}

template<class T>
void DoublyLinkedList<T>::addFirstNode(T item) {
    Node<T>* n = createNode(item);
//    Node<T>* special = new Node<T>;

    head = n;
    tail = n;

//    special->prev = tail;
//    special->next = head;
//
//    head->prev = special;
//    tail->next = special;
}

template<class T>
void DoublyLinkedList<T>::remove(Node<T> *node) {
    if (isEmpty() || node == nullptr) {
        return;
    }

    if (head == node) {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }

    delete node;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const DoublyLinkedList<T> &list) {
    Node<T>* temp = list.head;
    while (temp != nullptr) {
        os << temp->data << " ";
        temp = temp->next;
    }

    return os;
}

template<class T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList &rhs) {
    DoublyLinkedList<T> temp(rhs);
    std::swap(temp->head, head);
    return *this;
}

template<class T>
void DoublyLinkedList<T>::operator+=(const T& item) {
    push_back(item);
}

#endif //CS008_DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_CPP