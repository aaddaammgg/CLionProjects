//
// Created by Adam G. on 11/20/2021.
//

#include "BaseSuit.h"

BaseSuit::BaseSuit() {

}

BaseSuit::BaseSuit(SuitsENUM suit) : suit(suit) {

}

SuitsENUM BaseSuit::getSuit() {
    return suit;
}

void BaseSuit::setSuit(SuitsENUM suit) {
    this->suit = suit;
}

SuitsColorENUM BaseSuit::getColor() {
    return ((suit == SPADES) || (suit == CLUBS)) ? BLACK : RED;
}

void BaseSuit::setColor(SuitsColorENUM color) {

}

std::string BaseSuit::toString() const {
    // SPADES = 1, HEARTS, CLUBS, DIAMONDS
    std::string s[] = {"Spades", "Hearts", "Clubs", "Diamonds"};

    return s[suit - 1];
}

int BaseSuit::toInt() const {
    return suit;
}
