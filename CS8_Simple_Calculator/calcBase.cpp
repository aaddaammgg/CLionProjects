//
// Created by Adam G. on 1/16/2022.
//

#include "calcBase.h"

calcBase::calcBase() : calcBase(0, 0) {

}

calcBase::calcBase(double x, double y) : x(x), y(y) {

}

void calcBase::welcomeMsg() {
    std::cout << "Hello CS8! This is a basic addition calculator that has a history." << std::endl << std::endl;
}

void calcBase::calculateResult(ArithmeticTypeENUM at) {
    switch (at) {
        case AT_ADD:
            setResult(getX() + getY());
            break;
        case AT_SUB:
            setResult(getX() - getY());
            break;
    }
}

void calcBase::outputResult(ArithmeticTypeENUM at) const {
    std::cout << "--> " << getX();

    switch (at) {
        case AT_ADD:
            std::cout << " + ";
            break;
        case AT_SUB:
            std::cout << " - ";
            break;
    }

    std::cout << getY() << " = " << getResult() << std::endl << std::endl;
}

void calcBase::getUserInput(inputENUM val) {
    double temp = 0;

    std::cout << "Enter a number for " << ((val == INPUT_X) ? "X" : "Y") << ":" << std::endl;
    std::cin >> temp;

    if (val == INPUT_X) {
        setX(temp);
    } else {
        setY(temp);
    }
}

calcHistory calcBase::getHistory() {
    return history;
}

void calcBase::setHistory(calcHistory his) {
    this->history = his;
}

double calcBase::getX() const {
    return x;
}

double calcBase::getY() const {
    return y;
}

double calcBase::getResult() const {
    return result;
}

void calcBase::setX(double x) {
    this->x = x;
}

void calcBase::setY(double y) {
    this->y = y;
}

void calcBase::setResult(double val) {
    this->result = val;
    history.push(val);
}
