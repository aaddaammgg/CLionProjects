//
// Created by Adam G. on 3/16/22.
//

#ifndef CS008_HEAP_HEAP_H
#define CS008_HEAP_HEAP_H

#include <vector>

template <class T>
class Heap {
private:
    std::vector<T> data;
    void reheapifyUp(int childIndex);
    void reheapifyDown(int parentIndex);
    int getParent(int childIndex);
    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);

public:
    Heap();

    T top();
    void pop();
    void push(const T& item);
    int size();
    bool empty();
};


#endif //CS008_HEAP_HEAP_H
