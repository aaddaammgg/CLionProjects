//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_BASECARD_H
#define KINGS_CORNER_BASECARD_H

#include <iostream>
#include "BaseRank.h"
#include "BaseSuit.h"

class BaseCard {
private:
    BaseRank _rank;
    BaseSuit _suit;
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


#endif //KINGS_CORNER_BASECARD_H
