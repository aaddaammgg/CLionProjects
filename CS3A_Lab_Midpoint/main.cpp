#include <iostream>

#include "Midpoint.h"

int main() {
    Coordinate coord1(-3, 3);
    Coordinate coord2(5, 3);

    Coordinate midpoint = Midpoint(coord1, coord2);

    std::cout << "X: " << midpoint.getX() << " Y: " << midpoint.getY() << std::endl;
    return 0;
}
