//
// Created by NAMEHERE on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_BASERANK_H
#define CS3A_KINGS_CORNER_BASERANK_H

#include <string>
#include "RanksENUM.h"
#include "SuitsColorENUM.h"

class BaseRank {
private:
    RanksENUM rank;
    SuitsColorENUM color;
public:
    BaseRank();
    BaseRank(RanksENUM rank);

    RanksENUM getRank();
    SuitsColorENUM getColor();

    void setColor(SuitsColorENUM color);
    void setRank(RanksENUM rank);

    std::string toString() const;
    std::string toShortString() const;
    int toInt();
};

#endif //CS3A_KINGS_CORNER_BASERANK_H
