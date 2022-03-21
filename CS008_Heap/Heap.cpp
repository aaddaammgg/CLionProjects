//
// Created by Adam G. on 3/16/22.
//

#ifndef CS008_HEAP_HEAP_CPP
#define CS008_HEAP_HEAP_CPP

#include "Heap.h"

template<class T>
Heap<T>::Heap() {

}

template<class T>
void Heap<T>::reheapifyUp(int childIndex) {
    int parentIndex = getParent(childIndex);
    if (data[parentIndex] < data[childIndex]) {
        std::swap(data[childIndex], data[parentIndex]);
        reheapifyUp(parentIndex);
    }
}

template<class T>
void Heap<T>::reheapifyDown(int parentIndex) {
    int left = getLeftChild(parentIndex);
    int right = getRightChild(parentIndex);

    int largest = parentIndex;

    if (left < size() && data[left] > data[parentIndex]) {
        largest = left;
    }

    if (right < size() && data[right] > data[largest]) {
        largest = right;
    }

    if (largest != parentIndex) {
        std::swap(data[parentIndex], data[largest]);
        reheapifyDown(largest);
    }
}

template<class T>
int Heap<T>::getParent(int childIndex) {
    return (childIndex - 1) / 2;
}

template<class T>
int Heap<T>::getLeftChild(int parentIndex) {
    return parentIndex * 2 + 1;
}

template<class T>
int Heap<T>::getRightChild(int parentIndex) {
    return parentIndex * 2 + 2;
}

template<class T>
T Heap<T>::top() {
    return data.front();
}

template<class T>
void Heap<T>::pop() {
    if (!empty()) {
        data[0] = data.back();
        data.pop_back();
        reheapifyDown(0);
    }
}

template<class T>
void Heap<T>::push(const T &item) {
    data.push_back(item);
    reheapifyUp(data.size() - 1);
}

template<class T>
int Heap<T>::size() {
    return data.size();
}

template<class T>
bool Heap<T>::empty() {
    return data.empty();
}

template<class T>
Heap<T> &Heap<T>::operator+=(const T &rhs) {
    push(rhs);
    return *this;
}

#endif //CS008_HEAP_HEAP_CPP