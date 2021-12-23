//
// Created by Adam G. on 12/10/2021.
//

#include "Person.h"

Person::Person() {

}

Person::Person(std::string name) : name(name) {

}

Person::Person(const Person &object) {
    *this = object;
}

std::string Person::getName() const {
    return name;
}

Person &Person::operator=(const Person &rhs) {
    this->name = rhs.getName();
    return *this;
}

std::istream &operator>>(std::istream &is, Person &person) {
    is >> person.name;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << person.getName() << std::endl;
    return os;
}
