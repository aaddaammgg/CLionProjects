//
// Created by Adam G. on 11/15/2021.
//

#ifndef CS3A_SFML_TIPS_STATES_H
#define CS3A_SFML_TIPS_STATES_H

#include "StatesENUM.h"

class States {
private:
    bool states[LAST_STATES];
public:
    bool isEnabled(StatesENUM state) const;
    void enableState(StatesENUM state);
    void disableState(StatesENUM state);
};


#endif //CS3A_SFML_TIPS_STATES_H
