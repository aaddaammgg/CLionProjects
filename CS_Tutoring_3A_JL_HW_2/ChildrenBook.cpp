//
// Created by Quantum on 4/11/2023.
//

#include "ChildrenBook.h"

int ChildrenBook::getAge() const {
    return age;
}

//std::string ChildrenBook::getString() {
//    std::string print;
//
//    print += getTitle() + "(" + std::to_string(getCode()) + ")";
//
//    return print;
//}

void ChildrenBook::setAge(int age) {
    ChildrenBook::age = age;
}

CATEGORY ChildrenBook::getCategory() {
    return CATEGORY::CHILDREN_BOOK;
}
