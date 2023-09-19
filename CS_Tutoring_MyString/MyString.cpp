//
// Created by Adam G. on 9/18/2023.
//

#include "MyString.h"

MyString::MyString(const char *str) {
    size = strlen(str);
    seq = new char[size + 1];

    strcpy(seq, str);
    seq[size] = '\0';
}

MyString::~MyString() {
    delete[] seq;
}

size_t MyString::getSize() const {
    return size;
}

std::ostream &operator<<(std::ostream &os, const MyString &obj) {
    os << obj.seq;

    return os;
}

std::istream &operator>>(std::istream &is, const MyString &obj) {
    is.get(obj.seq, 100);

    return is;
}
