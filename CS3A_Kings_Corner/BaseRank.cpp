//
// Created by Adam G. on 11/20/2021.
//

#include "BaseRank.h"

BaseRank::BaseRank() {

}

BaseRank::BaseRank(RanksENUM rank) : rank(rank) {

}

RanksENUM BaseRank::getRank() {
    return rank;
}

void BaseRank::setRank(RanksENUM rank) {

}

SuitsColorENUM BaseRank::getColor() {
    return color;
}

void BaseRank::setColor(SuitsColorENUM color) {
    this->color = color;
}

std::string BaseRank::toString() const {
    std::string r[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                       "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    return r[rank - 1];
}

std::string BaseRank::toShortString() const {
    if (rank > 1 && rank < 11)
        return std::to_string((int)rank);

    return std::string() + toString()[0]; // <----- now it works
}

int BaseRank::toInt() {
    return rank;
}