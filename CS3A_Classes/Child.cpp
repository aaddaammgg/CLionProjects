//
// Created by Quantum on 9/30/2021.
//

#include "Child.h"

Child::Child() : Child(Name(), Date(), 1) {
    std::cout << "I am a child" << std::endl;
}
Child::Child(Name name, Date birthday) : Child(name, birthday, 1) {

}
Child::Child(Name name, Date birthday, int shoeSize) : Person(name, birthday), shoeSize(shoeSize) {

}

int Child::getShoeSize() const {
    return shoeSize;
}

void Child::setShoeSize(int shoeSize) {
    Child::shoeSize = shoeSize;
}