//
// Created by Adam G. on 12/10/2021.
//

#include "Percent.h"

Percent::Percent() {

}

Percent::Percent(int percent_value) : value(percent_value) {

}

bool operator==(const Percent &first, const Percent &second) {
    return (first.value == second.value);
}

bool operator<(const Percent &first, const Percent &second) {
    return (first.value < second.value);
}

Percent operator*(const Percent &amount1, const Percent &amount2) {
    Percent temp;
    temp.value = amount1.value * amount2.value;

    return temp;
}

Percent operator+(const Percent &amount1, const Percent &amount2) {
    Percent temp;
    temp.value = amount1.value + amount2.value;

    return temp;
}

Percent operator-(const Percent &amount1, const Percent &amount2) {
    Percent temp;
    temp.value = amount1.value - amount2.value;

    return temp;
}

std::istream &operator>>(std::istream &ins, Percent &object) {
    ins >> object.value;

    return ins;
}

std::ostream &operator<<(std::ostream &outs, Percent &object) {
    outs << object.value / 100.0 << std::endl;

    return outs;
}
