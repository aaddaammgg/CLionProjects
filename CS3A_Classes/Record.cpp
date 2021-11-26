//
// Created by Quantum on 9/30/2021.
//

#include "Record.h"

///getter
Person Record::getPerson() {
    return person;
}

///setter
void Record::setPerson(Person person) {
    this->person = person;
}

///constructors
Record::Record() = default;

Record::Record(Person person) : person(person) {

}
