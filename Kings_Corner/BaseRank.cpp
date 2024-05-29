//
// Created by Adam G. on 10/1/2023.
//

#include "BaseRank.h"

std::string BaseRank::_rankStr[] = {"Ace", "Two", "Three",
                                    "Four", "Five", "Six",
                                    "Seven","Eight", "Nine",
                                    "Ten", "Jack", "Queen", "King"};

BaseRank::BaseRank() : BaseRank(ACE) {

}

BaseRank::BaseRank(RanksENUM rank) : _rank(rank) {

}

RanksENUM BaseRank::getRank() {
    return _rank;
}

SuitsColorENUM BaseRank::getColor() {
    return _color;
}

void BaseRank::setRank(RanksENUM rank) {
    _rank = rank;
}

void BaseRank::setColor(SuitsColorENUM color) {
    _color = color;
}

std::string BaseRank::toString() const {
    return _rankStr[_rank - 1];
}

std::string BaseRank::toShortString() const {
    if (_rank > 1 && _rank < 11)
        return std::to_string((int)_rank);

    return std::string() + toString()[0]; // <----- now it works
}

int BaseRank::toInt() {
    return _rank;
}
