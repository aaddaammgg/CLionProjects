//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH11_PRACTICE_Q2_PAIRS_H
#define CS3A_CH11_PRACTICE_Q2_PAIRS_H

#include <iostream>

class Pairs {
private:
    int f;
    int s;
public:
    Pairs();
    Pairs(int first, int second);

    friend std::istream& operator>>(std::istream& ins, Pairs& second);
    friend std::ostream& operator<<(std::ostream& outs, const Pairs& second);

    friend Pairs operator*(const Pairs& amount1, const Pairs& amount2);
    friend Pairs operator+(const Pairs& amount1, const Pairs& amount2);
    friend Pairs operator-(const Pairs& amount1, const Pairs& amount2);
    friend Pairs operator-(const Pairs& amount);
};


#endif //CS3A_CH11_PRACTICE_Q2_PAIRS_H
