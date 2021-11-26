//
// Created by Adam G. on 11/15/2021.
//

#include "States.h"

bool States::isEnabled(StatesENUM state) const {
    return states[state];
}

void States::enableState(StatesENUM state) {
    states[state] = true;
}

void States::disableState(StatesENUM state) {
    states[state] = false;
}
