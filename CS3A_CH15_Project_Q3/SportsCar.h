//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PROJECT_Q3_SPORTSCAR_H
#define CS3A_CH15_PROJECT_Q3_SPORTSCAR_H

#include <iostream>
#include "Car.h"

class SportsCar : public Car {
private:
    bool spoiler;
    int numTurbos;
    float horsePower;
public:
    SportsCar();
    SportsCar(bool spoiler, int numTurbos, float horsePower);

    static void boostMode();

    friend std::ostream& operator<<(std::ostream& os, const SportsCar& sportsCar);
};


#endif //CS3A_CH15_PROJECT_Q3_SPORTSCAR_H
