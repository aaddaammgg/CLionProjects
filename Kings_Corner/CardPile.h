//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_CARDPILE_H
#define KINGS_CORNER_CARDPILE_H

#include "CardHand.h"

class CardPile : public CardHand {
public:
    BaseCard& firstCard();
    BaseCard& lastCard();

    int getSize();

    void combinePile(CardPile& pile);

    CardPile& operator +=(CardPile& rhs);
    friend std::ostream& operator<<(std::ostream& os, const CardPile& pile);
};


#endif //KINGS_CORNER_CARDPILE_H
