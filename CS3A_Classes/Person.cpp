//
// Created by Quantum on 9/30/2021.
//

#include "Person.h"

Name Person::getName() {
    return name;
}

Date Person::getBirthday() {
    return birthday;
}

void Person::setName(Name name) {
    this->name = name;
}

void Person::setBirthday(Date birthday) {
    this->birthday = birthday;
}


Person::Person() = default;

Person::Person(Name name, Date birthday) : name(name), birthday(birthday) {

}