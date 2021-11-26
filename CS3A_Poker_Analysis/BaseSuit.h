//
// Created by Adam G. on 10/21/2021.
//

#ifndef CS3A_POKER_ANALYSIS_BASESUIT_H
#define CS3A_POKER_ANALYSIS_BASESUIT_H

#include <string>
#include "SuitsENUM.h"
#include "SuitsColorENUM.h"

class BaseSuit {
private:
    SuitsENUM suit;

public:
    BaseSuit();
    BaseSuit(SuitsENUM suit);

    SuitsENUM getSuit();
    SuitsColorENUM getColor();

    void setSuit(SuitsENUM suit);
    void setColor(SuitsColorENUM color);

    std::string toString() const;
    int toInt() const;
};

#endif //CS3A_POKER_ANALYSIS_BASESUIT_H
