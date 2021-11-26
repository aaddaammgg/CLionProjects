//
// Created by Quantum on 9/30/2021.
//

#ifndef CS3A_CLASSES_RECORD_H
#define CS3A_CLASSES_RECORD_H


#include "Person.h"
#include "Car.h"

class Record {
private:
    Person person;
    Car car;
public:
    ///getter
    Person getPerson();

    ///setter
    void setPerson(Person person);

    ///constructor
    Record();
    Record(Person person);
};


#endif //CS3A_CLASSES_RECORD_H
