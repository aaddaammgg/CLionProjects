//
// Created by Adam G. on 10/16/2021.
//

#ifndef CSA_LAB_NAMEDVECTOR_NAMEDVECTOR_H_CPP
#define CSA_LAB_NAMEDVECTOR_NAMEDVECTOR_H_CPP
#include "NamedVector.h"

template <class T>
T NamedVector<T>::getName() {
    //return 1;
}

template <class T>
void NamedVector<T>::setName(T name) {
    this->name = name;
}

template <class T>
NamedVector<T> operator+(const NamedVector<T> &lhs, const NamedVector<T> &rhs) {
    NamedVector<T> temp;

    for (int i = 0; i < lhs.size(); i++) {
        temp.push_back(lhs[i]);
    }

    for (int i = 0; i < rhs.size(); i++) {
        temp.push_back(rhs[i]);
    }

    return temp;
}

template <class T>
std::ostream& operator<<(std::ostream &out, const NamedVector<T> &v) {
    return out;
}

#endif