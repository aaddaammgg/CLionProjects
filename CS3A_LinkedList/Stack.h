//
// Created by Adam G. on 11/27/2021.
//

#ifndef CS3A_LINKEDLIST_STACK_H
#define CS3A_LINKEDLIST_STACK_H

#include "LinkedList.h"

template<class T>
class Stack {
private:
    LinkedList<T> list;
public:
    Stack();
    ~Stack();

    void push(const T& item);
    void pop();
    T& front();
    T& back();
    bool isEmpty();
    int getSize();

    template <class S>
    friend std::ostream& operator<<(std::ostream& os, const Stack<S>& list);
};

#include "Stack.cpp"

#endif //CS3A_LINKEDLIST_STACK_H
