//
// Created by Adam G. on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_CARDHAND_H
#define CS3A_KINGS_CORNER_CARDHAND_H

#include <iostream>
#include <vector>
#include "BaseCard.h"
#include <algorithm>

class CardHand {
private:
    std::vector<BaseCard> allCards;
public:
    CardHand();

    void addCard(BaseCard card);
    void sort();

    std::vector<BaseCard> getAllCards();

    friend std::ostream& operator<<(std::ostream& os, const CardHand& hand);
};


#endif //CS3A_KINGS_CORNER_CARDHAND_H
