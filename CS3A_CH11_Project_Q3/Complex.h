//
// Created by Adam G. on 10/24/2021.
//

#ifndef CS3A_CH11_PROJECT_Q3_COMPLEX_H
#define CS3A_CH11_PROJECT_Q3_COMPLEX_H

#include <ostream>

class Complex {
private:
    double real, imaginary;
public:
    Complex();
    Complex(double real_part);
    Complex(double real, double imaginary);

    double getReal() const;
    double getImaginary() const;

    void setReal(double real);
    void setImaginary(double imaginary);

    bool operator==(Complex& x) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& x);
    friend Complex operator+(Complex& x, Complex& y);
    friend Complex operator-(Complex& x, Complex& y);
    friend Complex operator*(Complex& x, Complex& y);

};


#endif //CS3A_CH11_PROJECT_Q3_COMPLEX_H
