//
// Created by Adam G. on 10/1/2023.
//

#include "BaseCard.h"

BaseCard::BaseCard() : BaseCard(ACE, HEARTS) {

}

BaseCard::BaseCard(BaseRank rank, BaseSuit suit) : _rank(rank), _suit(suit) {

}

BaseRank BaseCard::getRank() const {
    return _rank;
}

BaseSuit BaseCard::getSuit() const {
    return _suit;
}

void BaseCard::setRank(BaseRank rank) {
    _rank = rank;
}

void BaseCard::setSuit(BaseSuit suit) {
    _suit = suit;
}

bool operator<(const BaseCard &x, const BaseCard &y) {
    return std::make_pair(x.getRank().toInt(), x.getSuit().toInt()) < std::make_pair(y.getRank().toInt(), y.getSuit().toInt());
}

std::ostream &operator<<(std::ostream &os, const BaseCard &card) {
    os << card._rank.toString() << " of " << card._suit.toString();

    return os;
}
