//
// Created by Adam G. on 10/1/2023.
//

#include "CardHand.h"

CardHand::CardHand() {

}

void CardHand::addCard(BaseCard* card) {
    if (card == nullptr) {
        return;
    }

    _cards.push_back(card);
}

void CardHand::sort() {
    std::sort(_cards.rbegin(), _cards.rend());
}

void CardHand::emptyCards() {
    _cards.clear();
}

std::vector<BaseCard*> &CardHand::getCards() {
    return _cards;
}

std::ostream &operator<<(std::ostream &os, const CardHand &hand) {
    int i = 0;
    for (const auto& card : hand._cards) {
        os << i << ": " << *card << " RANK: " << card->getRank().toInt() << " SUIT: " << card->getSuit().toInt() << std::endl;
        i++;
    }

    return os;
}
