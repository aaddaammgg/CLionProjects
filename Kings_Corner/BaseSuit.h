//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_BASESUIT_H
#define KINGS_CORNER_BASESUIT_H

#include <string>
#include "SuitsENUM.h"
#include "SuitsColorENUM.h"

class BaseSuit {
private:
    SuitsENUM _suit;
    static std::string _suitStr[];
public:
    BaseSuit();
    BaseSuit(SuitsENUM suit);

    SuitsENUM getSuit();
    SuitsColorENUM getColor();

    void setSuit(SuitsENUM suit);

    std::string toString() const;
    int toInt() const;
};


#endif //KINGS_CORNER_BASESUIT_H
