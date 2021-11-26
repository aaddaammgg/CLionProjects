//
// Created by Quantum on 9/30/2021.
//

#include "Name.h"

///overloaded constructor
Name::Name(std::string firstName, char middleInitial, std::string lastName) :
firstName(firstName), middleInitial(middleInitial), lastName(lastName) {

}

Name::Name() : firstName("John"), middleInitial('D'), lastName("Smith") {

}

std::string Name::getFirstName() {
    return firstName;
}

std::string Name::getLastName() {
    return lastName;
}

char Name::getMiddleInitial() {
    return middleInitial;
}