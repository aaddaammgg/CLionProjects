//
// Created by Adam G. on 12/10/2021.
//

#include "Pairs.h"

Pairs::Pairs() {

}

Pairs::Pairs(int first, int second) : f(first), s(second) {

}

Pairs operator*(const Pairs &amount1, const Pairs &amount2) {
    Pairs temp(amount1.f * amount2.f, amount1.s * amount2.s);

    return temp;
}

std::istream &operator>>(std::istream &ins, Pairs &second) {
    ins >> second.f;
    ins >> second.s;

    return ins;
}

std::ostream &operator<<(std::ostream &outs, const Pairs &second) {
    outs << "(" << second.f << "," << second.s << ")" << std::endl;

    return outs;
}

Pairs operator+(const Pairs &amount1, const Pairs &amount2) {
    Pairs temp(amount1.f + amount2.f, amount1.s + amount2.s);

    return temp;
}

Pairs operator-(const Pairs &amount1, const Pairs &amount2) {
    Pairs temp(amount1.f - amount2.f, amount1.s - amount2.s);

    return temp;
}

Pairs operator-(const Pairs &amount) {
    Pairs temp(-amount.f, -amount.s);

    return temp;
}
