//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_DECK_H
#define KINGS_CORNER_DECK_H

#include <iostream>
#include <algorithm>
#include "BaseCard.h"

class Deck {
private:
    static const int DECK_SIZE = 52;
    int _cardIndex = 0;
    BaseCard _deck[DECK_SIZE];

    bool empty() const;
public:
    Deck();

    void shuffle();
    BaseCard& dealCard();
    BaseCard& at(int index);

    BaseCard& operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
};


#endif //KINGS_CORNER_DECK_H
