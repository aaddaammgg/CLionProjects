//
// Created by Adam G. on 2/23/22.
//

#ifndef CS008_BINARYSEARCHTREE_A_CPP
#define CS008_BINARYSEARCHTREE_A_CPP

#include "A.h"

template<class T>
A<T>::A() : x(1) {

}

template<class T>
A<T>::A(T a) : x(a) {

}

template<class T>
void A<T>::doSomething(void (*f)(T &)) {
    f(x);
}

#endif //CS008_BINARYSEARCHTREE_A_CPP