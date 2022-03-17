//
// Created by Adam G. on 3/16/22.
//

#include "Heap.h"

template<class T>
Heap<T>::Heap() {

}

template<class T>
void Heap<T>::reheapifyUp(int childIndex) {
    int parentIndex = getParent(childIndex);
    if (data[childIndex] > data[parentIndex]) {
        std::swap(data[childIndex], data[parentIndex]);
        reheapifyUp(parentIndex);
    }
}

template<class T>
void Heap<T>::reheapifyDown(int parentIndex) {

}

template<class T>
int Heap<T>::getParent(int childIndex) {
    return (childIndex - 1) / 2;
}

template<class T>
int Heap<T>::getLeftChild(int parentIndex) {
    return parentIndex * 2 + 2;
}

template<class T>
int Heap<T>::getRightChild(int parentIndex) {
    return parentIndex * 2 +1;
}

template<class T>
T Heap<T>::top() {
    return data.back();
}

template<class T>
void Heap<T>::pop() {
    int deleteIndex = data.size() - 1;
    int parent = getParent(deleteIndex);

    if (data[deleteIndex] < parent) {

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
