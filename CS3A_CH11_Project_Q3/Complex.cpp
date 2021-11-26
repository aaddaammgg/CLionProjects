//
// Created by Adam G. on 10/24/2021.
//

#include "Complex.h"

Complex::Complex() : Complex(0, 0) {

}

Complex::Complex(double real_part) : Complex(real_part, 0) {

}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {

}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

bool Complex::operator==(Complex &x) const {
    if (getReal() == x.getReal() && getImaginary() == x.getImaginary())
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const Complex &x) {
    os << x.getReal() << " ";

    if (x.getImaginary() < 0) {
        os << "- ";
        if (x.getImaginary() != -1)
            os << std::abs(x.getImaginary());
    } else {
        os << "+ ";
        if (x.getImaginary() != 1)
            os << x.getImaginary();
    }

    os << "i";

    return os;
}

Complex operator+(Complex &x, Complex &y) {
    Complex temp;
    temp.setReal(x.getReal() + y.getReal());
    temp.setImaginary(x.getImaginary() + y.getImaginary());

    return temp;
}

Complex operator-(Complex &x, Complex &y) {
    Complex temp;
    temp.setReal(x.getReal() - y.getReal());
    temp.setImaginary(x.getImaginary() - y.getImaginary());

    return temp;
}

Complex operator*(Complex &x, Complex &y) {
    Complex temp;
    temp.setReal(x.getReal() * y.getReal() - x.getImaginary() * y.getImaginary());
    temp.setImaginary(x.getReal() * y.getImaginary() + x.getImaginary() * y.getReal());

    return temp;
}
