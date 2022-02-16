//
// Created by Adam G. on 2/12/22.
//

#ifndef CS008_CH6_PROJECT_Q7_SHUFFLE_H
#define CS008_CH6_PROJECT_Q7_SHUFFLE_H

#include <algorithm>
#include <random>

template<class T, class U>
class Shuffle {
private:
    static int randomNumber(int i);
    static void swap(T& a, T& b);
public:
    static void shuffle(U& container);

};

#include "Shuffle.cpp"

#endif //CS008_CH6_PROJECT_Q7_SHUFFLE_H
