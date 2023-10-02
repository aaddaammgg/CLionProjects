//
// Created by Adam G. on 10/1/2023.
//

#include "CardPile.h"

BaseCard &CardPile::firstCard() {
    return getCards().front();
}

BaseCard &CardPile::lastCard() {
    return getCards().back();
}

int CardPile::getSize() {
    return (int)getCards().size();
}

void CardPile::combinePile(CardPile &pile) {
    for (const auto& card : pile.getCards()) {
        addCard(card);
    }

    pile.emptyCards();
}

CardPile &CardPile::operator+=(CardPile &rhs) {
    combinePile(rhs);

    return *this;
}

std::ostream &operator<<(std::ostream &os, const CardPile &pile) {
    os << (const CardHand&)pile;

    return os;
}
