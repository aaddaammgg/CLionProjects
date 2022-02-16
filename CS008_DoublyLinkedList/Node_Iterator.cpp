//
// Created by Adam G. on 2/7/22.
//

#ifndef CS008_DOUBLYLINKEDLIST_NODE_ITERATOR_CPP
#define CS008_DOUBLYLINKEDLIST_NODE_ITERATOR_CPP

#include "Node_Iterator.h"

template<class T>
Node_Iterator<T>::Node_Iterator() : current(nullptr) {

}

template<class T>
Node_Iterator<T>::Node_Iterator(Node<T> *node) : current(node) {

}

template<class T>
Node_Iterator<T> &Node_Iterator<T>::operator++() { // prefix
    current = current->next;

    return *this;
}

template<class T>
Node_Iterator<T> Node_Iterator<T>::operator++(int) { // postfix
    Node_Iterator<T> original = *this;
    current = current->next;

    return original;
}

template<class T>
Node_Iterator<T> &Node_Iterator<T>::operator--() { // prefix
    current = current->prev;

    return *this;
}

template<class T>
Node_Iterator<T> Node_Iterator<T>::operator--(int) { // postfix
    Node_Iterator<T> original = current;
    current = current->prev;

    return original;
}

template<class T>
T &Node_Iterator<T>::operator*() {
    return current->data;
}

template<class S>
bool operator==(const Node_Iterator<S> &lhs, const Node_Iterator<S> rhs) {
    return (lhs.current) == (rhs.current);
}

template<class S>
bool operator!=(const Node_Iterator<S> &lhs, const Node_Iterator<S> rhs) {
    return (lhs.current) != (rhs.current);
}

#endif //CS008_DOUBLYLINKEDLIST_NODE_ITERATOR_CPP