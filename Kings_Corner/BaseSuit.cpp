//
// Created by Adam G. on 10/1/2023.
//

#include "BaseSuit.h"

std::string BaseSuit::_suitStr[] = {"Spades", "Hearts", "Clubs", "Diamonds"};

BaseSuit::BaseSuit() : BaseSuit(HEARTS) {

}

BaseSuit::BaseSuit(SuitsENUM suit) : _suit(suit) {

}

SuitsENUM BaseSuit::getSuit() {
    return _suit;
}

SuitsColorENUM BaseSuit::getColor() {
    return ((_suit == SPADES) || (_suit == CLUBS)) ? BLACK : RED;
}

void BaseSuit::setSuit(SuitsENUM suit) {
    _suit = suit;
}

std::string BaseSuit::toString() const {
    return _suitStr[_suit - 1];
}

int BaseSuit::toInt() const {
    return _suit;
}
