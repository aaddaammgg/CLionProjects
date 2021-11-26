//
// Created by Adam G. on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_CARDHANDSCORER_H
#define CS3A_KINGS_CORNER_CARDHANDSCORER_H

#include "CardHand.h"
#include "PokerScore.h"

class CardHandScorer {
private:
    static int x;
public:
    CardHandScorer();
    static PokerScore scorePokerHand(CardHand ch, bool &noRoyalFlush);

};


#endif //CS3A_KINGS_CORNER_CARDHANDSCORER_H
