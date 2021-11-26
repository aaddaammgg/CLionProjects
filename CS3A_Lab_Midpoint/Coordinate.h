//
// Created by Adam G. on 9/29/2021.
//

#ifndef CS3A_LAB_MIDPOINT_COORDINATE_H
#define CS3A_LAB_MIDPOINT_COORDINATE_H

#include "Value.h"

class Coordinate {
private:
    Value x, y;
public:
    double getX();
    double getY();

    Coordinate();
    Coordinate(Value x, Value y);
};


#endif //CS3A_LAB_MIDPOINT_COORDINATE_H
