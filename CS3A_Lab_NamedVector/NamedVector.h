//
// Created by Adam G. on 10/16/2021.
//

#ifndef CSA_LAB_NAMEDVECTOR_NAMEDVECTOR_H
#define CSA_LAB_NAMEDVECTOR_NAMEDVECTOR_H

#include <vector>
#include <iostream>

template <class T>
class NamedVector : public std::vector<T> {
private:
    T name;
public:
    T getName();
    void setName(T name);

    template <class U>
    friend NamedVector<U> operator+(const NamedVector<U>& lhs, const NamedVector<U>& rhs);

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const NamedVector<U>& v);


};

#include "NamedVector.cpp"

#endif //CSA_LAB_NAMEDVECTOR_NAMEDVECTOR_H
