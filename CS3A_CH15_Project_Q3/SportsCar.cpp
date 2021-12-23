//
// Created by Adam G. on 12/10/2021.
//

#include "SportsCar.h"

SportsCar::SportsCar() {

}

SportsCar::SportsCar(bool spoiler, int numTurbos, float horsePower) : spoiler(spoiler), numTurbos(numTurbos), horsePower(horsePower) {

}

void SportsCar::boostMode() {
    std::cout << "the car is going very fast now" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const SportsCar &sportsCar) {
    os << "spoiler: " << (sportsCar.spoiler ? "true" : "false") << " numTurbos: " << sportsCar.numTurbos << " horsePower: " << sportsCar.horsePower << std::endl;

    return os;
}
