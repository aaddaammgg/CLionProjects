//
// Created by Adam G. on 11/28/2021.
//
#ifndef CS3A_LINKEDLIST_QUEUE_CPP
#define CS3A_LINKEDLIST_QUEUE_CPP

#include "Queue.h"

template<class T>
Queue<T>::Queue() {

}

template<class T>
Queue<T>::~Queue() {

}

template<class T>
void Queue<T>::push(const T &item) {
    list.push_back(item);
}

template<class T>
void Queue<T>::pop() {
    list.pop_front();
}

template<class T>
T &Queue<T>::front() {
    return list.front()->data;
}

template<class T>
T &Queue<T>::back() {
    return list.back()->data;
}

template<class T>
bool Queue<T>::isEmpty() {
    return list.getSize() == 0;
}

template<class T>
int Queue<T>::getSize() {
    return list.getSize();
}

template<class S>
std::ostream &operator<<(std::ostream &os, const Queue<S> &list) {
    return list.list;
}

#endif //CS3A_LINKEDLIST_QUEUE_CPP