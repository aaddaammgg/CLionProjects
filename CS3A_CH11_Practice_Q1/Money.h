//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH11_PRACTICE_Q1_MONEY_H
#define CS3A_CH11_PRACTICE_Q1_MONEY_H

#include <iostream>
#include <fstream>

class Money {
private:
    long all_cents;
public:
    Money();
    Money(long dollars);
    Money(long dollars, int cents);

    double get_value() const;

    Money percent(int percent_figure) const;

    friend std::istream& operator>>(std::istream& ins, Money& amount);
    friend std::ostream& operator<<(std::ostream& outs, const Money& amount);

    friend Money operator+(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount);
    friend bool operator==(const Money& amount1, const Money& amount2);

    bool operator<(const Money& rhs) const;
    bool operator<=(const Money& rhs) const;
    bool operator>(const Money& rhs) const;
    bool operator>=(const Money& rhs) const;
};


#endif //CS3A_CH11_PRACTICE_Q1_MONEY_H
