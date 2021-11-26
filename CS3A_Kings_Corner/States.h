//
// Created by Adam G. on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_STATES_H
#define CS3A_KINGS_CORNER_STATES_H

#include <map>
#include "StatesENUM.h"

class States {
private:
    std::map<StatesENUM, bool> states;
public:
    bool isEnabled(StatesENUM state) const;
    void enableState(StatesENUM state);
    void disableState(StatesENUM state);
};


#endif //CS3A_KINGS_CORNER_STATES_H
