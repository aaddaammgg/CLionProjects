//
// Created by Adam G. on 12/10/2021.
//

#include "Shape.h"

Shape::Shape() : name("") {

}

Shape::Shape(std::string name) : name(name) {

}

std::string Shape::getName() {
    return this->name;
}

void Shape::setName(std::string newName) {
    this->name = newName;
}
