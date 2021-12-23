//
// Created by NAMEHERE on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_BASECARD_H
#define CS3A_KINGS_CORNER_BASECARD_H

#include "BaseRank.h"
#include "BaseSuit.h"
#include <iostream>
#include <tuple>

class BaseCard {
private:
    BaseRank rank;
    BaseSuit suit;
public:
    BaseCard();
    BaseCard(BaseRank rank, BaseSuit suit);

    BaseRank getRank() const;
    BaseSuit getSuit() const;

    void setRank(BaseRank rank);
    void setSuit(BaseSuit suit);

    friend bool operator<(const BaseCard &x, const BaseCard &y);
    friend std::ostream& operator<<(std::ostream& os, const BaseCard& card);
};


#endif //CS3A_KINGS_CORNER_BASECARD_H
