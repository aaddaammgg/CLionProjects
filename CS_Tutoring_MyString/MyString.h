//
// Created by Adam G. on 9/18/2023.
//

#ifndef CS_TUTORING_MYSTRING_MYSTRING_H
#define CS_TUTORING_MYSTRING_MYSTRING_H

#include <iostream>
#include <cstring>

class MyString {
private:
    char* seq = nullptr;
    size_t size = 0;

public:
    MyString() = default;
    explicit MyString(const char *str);
    ~MyString();

    size_t getSize() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
    friend std::istream& operator>>(std::istream& is, const MyString& obj);
};


#endif //CS_TUTORING_MYSTRING_MYSTRING_H
