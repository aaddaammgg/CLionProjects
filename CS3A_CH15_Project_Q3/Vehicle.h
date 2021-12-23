//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PROJECT_Q3_VEHICLE_H
#define CS3A_CH15_PROJECT_Q3_VEHICLE_H

#include <iostream>
#include <string>
#include "Person.h"

class Vehicle {
private:
    std::string manufactureName;
    int cylinders;
    Person owner;
public:
    Vehicle();
    Vehicle(std::string manufactureName,int cylinders, const Person& person);

    void setOwner(const Person& person);
    Person& getOwner();

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
};


#endif //CS3A_CH15_PROJECT_Q3_VEHICLE_H
