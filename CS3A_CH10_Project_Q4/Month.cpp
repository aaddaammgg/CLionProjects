//
// Created by Adam G. on 10/5/2021.
//

#include "Month.h"

Month::Month(char firstLetter, char secondLetter, char thirdLetter) : secondLetter(secondLetter) {
    this->firstLetter = firstLetter;
    Month::thirdLetter = thirdLetter;
    charToInt(firstLetter, secondLetter, thirdLetter);
}

Month::Month(int month) {
    (*this).month = month;
    intToChar(month);
}

Month::Month() : Month('J', 'a', 'n') {

}

void Month::setMonth(int month) {
    this->month = month;
}

void Month::setMonth(char firstLetter, char secondLetter, char thirdLetter) {
    this->firstLetter = firstLetter;
    this->secondLetter = secondLetter;
    this->thirdLetter = thirdLetter;
}

int Month::getMonth() {
    return month;
}

std::string Month::getMonthAsLetters() {
    std::string temp = {firstLetter, secondLetter, thirdLetter};
    return temp;
}

void Month::intToChar(int month) {
    switch (month) {
        case 1:
            setMonth('J', 'a', 'n');
            break;
        case 2:
            setMonth('F', 'e', 'b');
            break;
        case 3:
            setMonth('M', 'a', 'r');
            break;
        case 4:
            setMonth('A', 'p', 'r');
            break;
        case 5:
            setMonth('M', 'a', 'y');
            break;
        case 6:
            setMonth('J', 'u', 'n');
            break;
        case 7:
            setMonth('J', 'u', 'l');
            break;
        case 8:
            setMonth('A', 'u', 'g');
            break;
        case 9:
            setMonth('S', 'e', 'p');
            break;
        case 10:
            setMonth('O', 'c', 't');
            break;
        case 11:
            setMonth('N', 'o', 'v');
            break;
        case 12:
            setMonth('D', 'e', 'c');
            break;
        default:
            setMonth('0', '0', '0');
    }
}

void Month::charToInt(char firstLetter, char secondLetter, char thirdLetter) {
    switch (firstLetter) {
        case 'J':
            if (secondLetter == 'a')
                setMonth(1);
            else if (thirdLetter == 'n')
                setMonth(6);
            else
                setMonth(7);
            break;
        case 'F':
            setMonth(2);
            break;
        case 'M':
            if (thirdLetter == 'r')
                setMonth(3);
            else
                setMonth(5);
            break;
        case 'A':
            if (secondLetter == 'p')
                setMonth(4);
            else
                setMonth(8);
            break;
        case 'S':
            setMonth(8);
            break;
        case 'O':
            setMonth(10);
            break;
        case 'N':
            setMonth(11);
            break;
        case 'D':
            setMonth(12);
            break;
    }
}
