//
// Created by Adam G. on 12/7/2021.
//

#ifndef CS3A_KINGS_CORNER_BASEPLAYER_H
#define CS3A_KINGS_CORNER_BASEPLAYER_H

#include "CardPile.h"

class BasePlayer {
private:
    CardPile cardPile;
public:
    BasePlayer();

    CardPile& getCardPile();
};


#endif //CS3A_KINGS_CORNER_BASEPLAYER_H
