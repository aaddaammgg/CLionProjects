//
// Created by NAMEHERE on 11/27/2021.
//

#include "CardPile.h"

void CardPile::addCard(BaseCard card) {
    ch.addCard(card);
}

void CardPile::sort() {
    ch.sort();
}

int CardPile::getSize() {
    return ch.getAllCards().size();
}

CardHand CardPile::getPile() {
    return this->ch;
}

BaseCard CardPile::firstCard() {
    return ch.getAllCards().front();
}

BaseCard CardPile::lastCard() {
    return ch.getAllCards().back();
}

void CardPile::combinePile(CardPile pile) {
//    CardPile temp;
    for (auto i : pile.getPile().getAllCards()) {
        std::cout << "CARDPILE: "  << i.getRank().toInt() << std::endl;
//        temp.addCard(i);
        this->addCard(i);
    }

    std::cout << getPile() << std::endl;

    pile.getPile().emptyCards();
}

CardPile& CardPile::operator+=(const CardPile &rhs) {
    for (auto i : rhs.ch.getAllCards()) {
        this->addCard(i);
    }

    std::cout << this->getPile() << std::endl;

//    rhs.ch.emptyCards();

    return *this;
}

std::ostream &operator<<(std::ostream &os, const CardPile &pile) {
    int i = 0;
    for (auto card : pile.ch.getAllCards()) {
        os << i << ": " << card << " RANK: " << card.getRank().toInt() << " SUIT: " << card.getSuit().toInt() << std::endl;
        i++;
    }

    return os;
}
