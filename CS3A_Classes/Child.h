//
// Created by Quantum on 9/30/2021.
//

#ifndef CS3A_CLASSES_CHILD_H
#define CS3A_CLASSES_CHILD_H

#include "Person.h"

// : public Person is inheriting
class Child : public Person {
private:
    int shoeSize{};

public:
    Child();
    Child(Name name, Date birthday);
    Child(Name name, Date birthday, int shoeSize);

    int getShoeSize() const;

    void setShoeSize(int shoeSize);
};

#endif //CS3A_CLASSES_CHILD_H
