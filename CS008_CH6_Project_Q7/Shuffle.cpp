//
// Created by Adam G. on 2/12/22.
//

#ifndef CS008_CH6_PROJECT_Q7_SHUFFLE_CPP
#define CS008_CH6_PROJECT_Q7_SHUFFLE_CPP

#include "Shuffle.h"

template<class T, class U>
int Shuffle<T, U>::randomNumber(int i) {
    return rand() % i;
}

template<class T, class U>
void Shuffle<T, U>::swap(T& a, T& b) {
    T temp = std::move( a );
    a = std::move(b);
    b = std::move(temp);
}

template<class T, class U>
void Shuffle<T, U>::shuffle(U &container) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(container.begin(), container.end(), g);
}

#endif //CS008_CH6_PROJECT_Q7_SHUFFLE_CPP
