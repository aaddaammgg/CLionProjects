//
// Created by NAMEHERE on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_DECK_H
#define CS3A_KINGS_CORNER_DECK_H

#include "BaseCard.h"
#include <iostream>
#include <algorithm>
#include <chrono>

class Deck {
private:
    bool empty();
    int cardIndex;
    static const int DECK_SIZE = 52;
    BaseCard deck[DECK_SIZE];
public:
    Deck();
    void shuffle();
    BaseCard dealCard();
    BaseCard getCardAt(int index);
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
};


#endif //CS3A_KINGS_CORNER_DECK_H
