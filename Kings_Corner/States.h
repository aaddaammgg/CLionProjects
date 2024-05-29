//
// Created by Adam G. on 11/20/2021.
//

#ifndef STATES_H
#define STATES_H

#include <map>
#include <functional>
#include "StatesENUM.h"

#include <iostream>

class States {
private:
    std::map<StatesENUM, bool> states;
public:

    bool isEnabled(StatesENUM state) const;
    void enableState(StatesENUM state);
    void disableState(StatesENUM state);
protected:
    std::function<void(StatesENUM)> onChangeState;
    void setOnChangeState(std::function<void(StatesENUM)> func);
};


#endif //STATES_H
