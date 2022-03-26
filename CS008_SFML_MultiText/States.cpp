//
// Created by Adam G. on 11/20/2021.
//

#include "States.h"

void States::onStateChange(StatesENUM state) {

}

bool States::isEnabled(StatesENUM state) const {
    if (states.find(state) == states.end())
        return false;
    return states.at(state);
}

void States::enableState(StatesENUM state) {
    states[state] = true;
    onStateChange(state);
}

void States::disableState(StatesENUM state) {
    states[state] = false;
    onStateChange(state);
}