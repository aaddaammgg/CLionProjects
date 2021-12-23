//
// Created by NAMEHERE on 11/27/2021.
//

#ifndef CS3A_KINGS_CORNER_CARDPILE_H
#define CS3A_KINGS_CORNER_CARDPILE_H

#include "CardHand.h"

class CardPile {
private:
    CardHand ch;
public:

    void addCard(BaseCard card);
    void sort();

    CardHand getPile();
    BaseCard firstCard();
    BaseCard lastCard();

    int getSize();

    void combinePile(CardPile pile);

    CardPile& operator +=(const CardPile& rhs);
    friend std::ostream& operator<<(std::ostream& os, const CardPile& pile);
};


#endif //CS3A_KINGS_CORNER_CARDPILE_H
