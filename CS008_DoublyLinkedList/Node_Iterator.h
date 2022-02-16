//
// Created by Adam G. on 2/7/22.
//

#ifndef CS008_DOUBLYLINKEDLIST_NODE_ITERATOR_H
#define CS008_DOUBLYLINKEDLIST_NODE_ITERATOR_H

#include <iterator>
#include "Node.h"

template<class T>
class Node_Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    Node<T>* current;
public:
    Node_Iterator();
    explicit Node_Iterator(Node<T>* node);

    Node_Iterator<T>& operator++(); // prefix
    Node_Iterator<T> operator++(int); // postfix
    Node_Iterator<T>& operator--(); // prefix
    Node_Iterator<T> operator--(int); // postfix

    T& operator*();

    template<class S>
    friend bool operator==(const Node_Iterator<S>& lhs, const Node_Iterator<S> rhs);

    template<class S>
    friend bool operator!=(const Node_Iterator<S>& lhs, const Node_Iterator<S> rhs);
};

#include "Node_Iterator.cpp"

#endif //CS008_DOUBLYLINKEDLIST_NODE_ITERATOR_H
