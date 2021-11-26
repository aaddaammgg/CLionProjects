//
// Created by Adam G. on 9/29/2021.
//

#include "Coordinate.h"

Coordinate::Coordinate() : Coordinate(0,0) {

}

Coordinate::Coordinate(Value x, Value y) : x(x), y(y) {

}

double Coordinate::getX() {
    return x.getValue();
}

double Coordinate::getY() {
    return y.getValue();
}
