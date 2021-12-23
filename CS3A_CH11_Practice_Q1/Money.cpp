//
// Created by Adam G. on 12/10/2021.
//

#include "Money.h"

Money::Money() {

}

Money::Money(long dollars) {
    all_cents = dollars * 100;
}

Money::Money(long dollars, int cents) {
    all_cents = (dollars * 100) + cents;
}

double Money::get_value() const {
    return all_cents;
}

Money Money::percent(int percent_figure) const {
    Money temp;
    temp.all_cents = (this->all_cents / 100) / percent_figure;

    return temp;
}

std::istream &operator>>(std::istream &ins, Money &amount) {
    ins >> amount.all_cents;

    return ins;
}

std::ostream &operator<<(std::ostream &outs, const Money &amount) {
    outs << "$" << amount.all_cents / 100.0 << std::endl;

    return outs;
}

Money operator+(const Money &amount1, const Money &amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;

    return temp;
}

Money operator-(const Money &amount1, const Money &amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;

    return temp;
}

Money operator-(const Money &amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;

    return temp;
}

bool operator==(const Money &amount1, const Money &amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

bool Money::operator<(const Money &rhs) const {
    return this->all_cents < rhs.all_cents;
}

bool Money::operator<=(const Money &rhs) const {
    return this->all_cents <= rhs.all_cents;
}

bool Money::operator>(const Money &rhs) const {
    return this->all_cents > rhs.all_cents;
}

bool Money::operator>=(const Money &rhs) const {
    return this->all_cents >= rhs.all_cents;
}
