//
// Created by Adam G. on 12/10/2021.
//

#include "Rectangle.h"

Rectangle::Rectangle() : Shape("Rectangle"), width(0), height(0) {

}

Rectangle::Rectangle(int width, int height) : Shape("Rectangle"), width(width), height(height) {

}

double Rectangle::getArea() {
    return width * height;
}

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(int newWidth) {
    this->width = newWidth;
}

void Rectangle::setHeight(int newHeight) {
    this->height = newHeight;
}
