//
// Created by Quantum on 4/11/2023.
//

#include "Person.h"

int Person::getID() const {
    return id;
}

const std::string &Person::getName() const {
    return name;
}

int Person::getCount() const {
    return count;
}

void Person::setId(int id) {
    Person::id = id;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

void Person::setCount(int count) {
    Person::count = count;
}
