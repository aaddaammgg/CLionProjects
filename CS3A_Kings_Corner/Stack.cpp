//
// Created by Adam G. on 11/27/2021.
//

#ifndef CS3A_LINKEDLIST_STACK_CPP
#define CS3A_LINKEDLIST_STACK_CPP

#include "Stack.h"

template<class T>
Stack<T>::Stack() {

}

template<class T>
Stack<T>::~Stack() {

}

template<class T>
void Stack<T>::push(const T &item) {
    list.push_back(item);
}

template<class T>
void Stack<T>::pop() {
    list.pop_back();
}

template<class T>
T &Stack<T>::front() {
    return list.front()->data;
}

template<class T>
T &Stack<T>::back() {
    return list.back()->data;
}

template<class T>
bool Stack<T>::isEmpty() {
    return list.getSize() == 0;
}

template<class T>
int Stack<T>::getSize() {
    return list.getSize();
}

template<class S>
std::ostream &operator<<(std::ostream &os, const Stack<S> &list) {
    os << list.list;
    return os;
}

#endif //CS3A_LINKEDLIST_STACK_CPP