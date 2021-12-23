#include <iostream>
#include "SportsCar.h"

int main() {
    Person adam("adam");

    std::cout << adam << std::endl;

    Car car1(false, true);
    car1.setOwner(adam);

    std::cout << car1 << std::endl;

    SportsCar sportsCar(true, 4, 2000);
    sportsCar.setOwner(adam);

    std::cout << sportsCar << std::endl;
    std::cout << sportsCar.getOwner() << std::endl;

    return 0;
}
