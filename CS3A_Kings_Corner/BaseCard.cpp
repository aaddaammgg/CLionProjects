//
// Created by Adam G. on 11/20/2021.
//

#include "BaseCard.h"

BaseCard::BaseCard() : BaseCard(ACE, HEARTS) {

}

BaseCard::BaseCard(BaseRank rank, BaseSuit suit) : rank(rank), suit(suit) {

}

BaseRank BaseCard::getRank() const {
    return rank;
}

BaseSuit BaseCard::getSuit() const {
    return suit;
}

void BaseCard::setRank(BaseRank rank) {
    rank.setColor(suit.getColor());
    this->rank = rank;
}

void BaseCard::setSuit(BaseSuit suit) {
    this->suit = suit;
}

bool operator<(const BaseCard &x, const BaseCard &y) {
    return std::make_pair(x.getRank().toInt(), x.getSuit().toInt()) < std::make_pair(y.getRank().toInt(), y.getSuit().toInt());
}

std::ostream& operator<<(std::ostream& os, const BaseCard& card) {
    os << card.rank.toString() << " of " << card.suit.toString();

    return os;
}