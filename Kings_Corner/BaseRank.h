//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_BASERANK_H
#define KINGS_CORNER_BASERANK_H

#include <string>
#include "RanksENUM.h"
#include "SuitsColorENUM.h"

class BaseRank {
private:
    RanksENUM _rank;
    SuitsColorENUM _color;

    static std::string _rankStr[];
public:
    BaseRank();
    BaseRank(RanksENUM rank);

    RanksENUM getRank();
    SuitsColorENUM getColor();

    void setRank(RanksENUM rank);
    void setColor(SuitsColorENUM color);

    std::string toString() const;
    std::string toShortString() const;
    int toInt();
};


#endif //KINGS_CORNER_BASERANK_H
