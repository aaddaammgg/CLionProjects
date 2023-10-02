//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_CARDHAND_H
#define KINGS_CORNER_CARDHAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "BaseCard.h"

class CardHand {
private:
    std::vector<BaseCard> _cards;
public:
    CardHand();

    void addCard(BaseCard card);
    void sort();
    void emptyCards();

    std::vector<BaseCard>& getCards();

    friend std::ostream& operator<<(std::ostream& os, const CardHand& hand);
};


#endif //KINGS_CORNER_CARDHAND_H
