//
// Created by Adam G. on 11/20/2021.
//

#include "States.h"

bool States::isEnabled(StatesENUM state) const {
    if (states.find(state) == states.end())
        return false;
    return states.at(state);
}

void States::enableState(StatesENUM state) {
    states[state] = true;

    if (onChangeState != nullptr) {
        onChangeState(state);
    }
}

void States::disableState(StatesENUM state) {
    states[state] = false;

    if (onChangeState != nullptr) {
        onChangeState(state);
    }
}

void States::setOnChangeState(std::function<void(StatesENUM)> func) {
    onChangeState = std::move(func);
}
