//
// Created by Quantum on 9/30/2021.
//

#ifndef CS3A_CLASSES_PERSON_H
#define CS3A_CLASSES_PERSON_H

#include <iostream>
#include "Name.h"
#include "Date.h"


class Person {
private:
    Name name;
    Date birthday;
public:
    ///getters
    Name getName();
    Date getBirthday();

    ///setters
    void setName(Name name);
    void setBirthday(Date birthday);

    ///constructors
    Person();
    Person(Name name, Date birthday);
};


#endif //CS3A_CLASSES_PERSON_H
