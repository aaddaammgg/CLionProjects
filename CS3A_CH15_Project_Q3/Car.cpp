//
// Created by Adam G. on 12/10/2021.
//

#include "Car.h"

Car::Car() : Car(true, true) {

}

Car::Car(bool coop, bool sunroof) : coop(coop), sunroof(sunroof) {

}

std::ostream &operator<<(std::ostream &os, const Car &car) {
    os << "coop: " << (car.coop ? "true" : "false") << " sunroof: " << (car.sunroof ? "true" : "false") << std::endl;

    return os;
}
