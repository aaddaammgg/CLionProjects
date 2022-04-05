//
// Created by Adam G. on 4/4/22.
//

#ifndef CS008_HASHTABLE_HASHTABLE_H
#define CS008_HASHTABLE_HASHTABLE_H

#include <cstddef>
#include "Record.h"

template <class T>
class HashTable {
private:
    static const std::size_t CAPACITY = 811;
    static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;
    int _size = 0;
    Record<T> data[CAPACITY];
    void find_index(int key, bool& found, int& index) const;
    bool isVacant(int index) const;
    std::size_t nextIndex(int index) const;
    int hash(int key) const;
    bool neverUsed(int index) const;

public:
    HashTable();

    void insert(int key, T value);
    void remove(int key);
    bool isPresent(int key);
    std::size_t find(int key) const;
    int size();
    T& operator[](unsigned int key);
};

#include "HashTable.cpp"

#endif //CS008_HASHTABLE_HASHTABLE_H
