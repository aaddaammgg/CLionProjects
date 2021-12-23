//
// Created by NAMEHERE on 11/20/2021.
//

#include "CardHand.h"

CardHand::CardHand() {

}

void CardHand::addCard(BaseCard card) {
    allCards.push_back(card);
}

void CardHand::sort() {
    std::sort(allCards.rbegin(), allCards.rend());
}

void CardHand::emptyCards() {
    allCards.clear();
}

std::vector<BaseCard> CardHand::getAllCards() const {
    return allCards;
}

std::ostream &operator<<(std::ostream &os, const CardHand &hand) {

    int i = 0;
    for (auto card : hand.allCards) {
        os << i << ": " << card << " RANK: " << card.getRank().toInt() << " SUIT: " << card.getSuit().toInt() << std::endl;
        i++;
    }

    return os;
}
