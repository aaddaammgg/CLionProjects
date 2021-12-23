//
// Created by Adam G. on 12/10/2021.
//

#include "Circle.h"

Circle::Circle() : Shape("Circle"), radius(0) {

}

Circle::Circle(int radius) : Shape("Circle"), radius(radius) {

}

double Circle::getArea() {
    return 3.14159 * radius * radius;
}

double Circle::getRadius() {
    return radius;
}

void Circle::setRadius(int newRadius) {
    this->radius = newRadius;
}
