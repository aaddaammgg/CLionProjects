//
// Created by Quantum on 9/30/2021.
//

#include "Car.h"

const std::string &Car::getMake() const {
    return make;
}

void Car::setMake(const std::string &make) {
    Car::make = make;
}

const std::string &Car::getModel() const {
    return model;
}

void Car::setModel(const std::string &model) {
    Car::model = model;
}

const Date &Car::getDate() const {
    return date;
}

void Car::setDate(const Date &date) {
    Car::date = date;
}

Car::Car() = default;

Car::Car(const std::string &make, const std::string &model, const Date &date) : make(make), model(model), date(date) {}