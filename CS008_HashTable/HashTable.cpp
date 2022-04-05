//
// Created by Adam G. on 4/4/22.
//

#ifndef CS008_HASHTABLE_HASHTABLE_CPP
#define CS008_HASHTABLE_HASHTABLE_CPP

#include "HashTable.h"

template<class T>
HashTable<T>::HashTable() {
    _size = 0;

    for (auto & i : data) {
        i.key = NEVER_USED;
    }
}

template<class T>
void HashTable<T>::find_index(int key, bool &found, int &index) const {
    index = hash(key);
    int count = 0;


    // Might need to do !neverUsed(index) instead of neverUsed(index)
    while (data[index].key != key && neverUsed(index) && count < CAPACITY) {
        count++;
        index = nextIndex(index);
    }

    found = data[index].key == key;
}

template<class T>
bool HashTable<T>::isVacant(int index) const {
    return data[index].key < 0;
}

template<class T>
std::size_t HashTable<T>::nextIndex(int index) const {
//    if (index == CAPACITY) {
//        return 0;
//    }

    return (index + 1) % CAPACITY;
}

template<class T>
int HashTable<T>::hash(int key) const {
    return key % CAPACITY;
}

template<class T>
bool HashTable<T>::neverUsed(int index) const {
    return data[index].key == NEVER_USED;
}

template<class T>
void HashTable<T>::insert(int key, T value) {
    bool already_present = false;
    std::size_t index;

    find_index(key, already_present, index);

    if (!already_present) {
        index = hash(key);
        while (!isVacant(index)) {
            index = nextIndex(index);
        }

        ++_size;
    }

    data[index].key = key;
    data[index].value = value;
}

template<class T>
void HashTable<T>::remove(int key) {
    bool found = false;
    std::size_t index;

    find_index(key, found, index);
    if (found) {
        data[index].key = PREVIOUSLY_USED;
        --_size;
    }
}

template<class T>
bool HashTable<T>::isPresent(int key) {
    bool found = false;
    int index;

    find_index(key, found, index);

    return index;
}

template<class T>
std::size_t HashTable<T>::find(int key) const {
    bool found = false;
    int index;

    find_index(key, found, index);

    if (!found) {
        return -1;
    }

    return index;
}

template<class T>
int HashTable<T>::size() {
    return _size;
}

template<class T>
T &HashTable<T>::operator[](unsigned int key) {
    return data;
}

#endif //CS008_HASHTABLE_HASHTABLE_CPP