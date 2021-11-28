//
// Created by Adam G. on 11/28/2021.
//

#ifndef CS3A_LINKEDLIST_QUEUE_H
#define CS3A_LINKEDLIST_QUEUE_H

#include "LinkedList.h"

template<class T>
class Queue {
private:
    LinkedList<T> list;
public:
    Queue();
    ~Queue();

    void push(const T& item);
    void pop();
    T& front();
    T& back();
    bool isEmpty();
    int getSize();

    template <class S>
    friend std::ostream& operator<<(std::ostream& os, const Queue<S>& list);
};


#endif //CS3A_LINKEDLIST_QUEUE_H
