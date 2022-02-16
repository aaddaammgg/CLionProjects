//
// Created by Adam Gonzalez on 1/26/22.
//

#include "Person.h"

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

const std::string &Person::getMiddleName() const {
    return middleName;
}

void Person::setMiddleName(const std::string &middleName) {
    Person::middleName = middleName;
}
