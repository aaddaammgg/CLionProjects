//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PROJECT_Q3_CAR_H
#define CS3A_CH15_PROJECT_Q3_CAR_H

#include <iostream>
#include "Vehicle.h"

class Car : public Vehicle {
private:
    bool coop;
    bool sunroof;
public:
    Car();
    Car(bool coop, bool sunroof);


    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};


#endif //CS3A_CH15_PROJECT_Q3_CAR_H
