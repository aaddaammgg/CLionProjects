//
// Created by Adam G. on 12/10/2021.
//

#include "Vehicle.h"

Vehicle::Vehicle() {

}

Vehicle::Vehicle(std::string manufactureName, int cylinders, const Person &person) : manufactureName(manufactureName), cylinders(cylinders), owner(person) {

}

void Vehicle::setOwner(const Person &person) {
    owner = person;
}

Person &Vehicle::getOwner() {
    return owner;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle) {
    os << "manufactureName: " << vehicle.manufactureName << " cylinders: " << vehicle.cylinders << std::endl;

    return os;
}
