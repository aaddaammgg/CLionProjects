//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH11_PRACTICE_Q3_PERCENT_H
#define CS3A_CH11_PRACTICE_Q3_PERCENT_H

#include <iostream>

class Percent {
private:
    int value;
public:
    Percent();
    Percent(int percent_value);

    friend bool operator==(const Percent& first, const Percent& second);
    friend bool operator<(const Percent& first, const Percent& second);

    friend Percent operator*(const Percent& amount1, const Percent& amount2);
    friend Percent operator+(const Percent& amount1, const Percent& amount2);
    friend Percent operator-(const Percent& amount1, const Percent& amount2);

    friend std::istream& operator>>(std::istream& ins, Percent& object);
    friend std::ostream& operator<<(std::ostream& outs, Percent& object);
};


#endif //CS3A_CH11_PRACTICE_Q3_PERCENT_H
