//
// Created by Adam G. on 9/30/2021.
//

#include "Midpoint.h"

Coordinate Midpoint(Coordinate coord1, Coordinate coord2) {
    double x = (coord1.getX() + coord2.getX()) / 2;
    double y = (coord1.getY() + coord2.getY()) / 2;

    Coordinate coord(x, y);

    return coord;
}