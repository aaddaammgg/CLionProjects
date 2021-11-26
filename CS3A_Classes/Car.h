//
// Created by Quantum on 9/30/2021.
//

#ifndef CS3A_CLASSES_CAR_H
#define CS3A_CLASSES_CAR_H


#include <string>
#include "Date.h"

class Car {
private:
    std::string make;
    std::string model;
    Date date;
public:

    const std::string &getMake() const;

    void setMake(const std::string &make);

    const std::string &getModel() const;

    void setModel(const std::string &model);

    const Date &getDate() const;

    void setDate(const Date &date);

    Car();

    Car(const std::string &make, const std::string &model, const Date &date);

};


#endif //CS3A_CLASSES_CAR_H
