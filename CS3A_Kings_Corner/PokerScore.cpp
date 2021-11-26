//
// Created by Adam G. on 11/20/2021.
//

#include "PokerScore.h"

PokerScore::PokerScore() {

}

PokerScore::PokerScore(CardHand ch) : ch(ch) {
    maxUniqueValue();
    maxNumberOfValue();
}

int &PokerScore::operator[](unsigned int index) {
    return scores[index];
}

void PokerScore::operator+=(const Scores &score) {
    scores[score]++;
}

void PokerScore::operator+=(const PokerScore &p) {
    for (int i = 0; i < PokerScore::HIGH_CARD + 1; i++) {
        scores[i] += p.scores[i];
    }
}

bool operator==(const PokerScore &p, PokerScore::Scores score) {

    return false;
}

std::ostream &operator<<(std::ostream &os, const PokerScore &ps) {
    for (int i = 0; i < PokerScore::HIGH_CARD + 1; i++) {
        os << PokerScore::scoresToString(static_cast<PokerScore::Scores>(i)) << ": " << ps.scores[i] << std::endl;
    }

    return os;
}

std::string PokerScore::scoresToString(PokerScore::Scores score) {
    std::string s[] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush",
                       "Straight", "Three of a Kind", "Two Pair", "One Pair", "High Card"};
    return s[score];
}

int* PokerScore::getScores() {
    return scores;
}

bool PokerScore::isHighCard() {
    return true;
}

bool PokerScore::isPair() {
    return maxNumber == 2;
}

bool PokerScore::isTwoPair() {
    return maxNumber == 2 && maxUnique == 3;
}

bool PokerScore::isThreeOfAKind() {
    return maxNumber == 3;
}

bool PokerScore::isStraight() {
    //std::vector<BaseCard> allCards = ch.getAllCards();
    int firstCard = ch.getAllCards()[0].getRank().toInt();
    int secondCard = ch.getAllCards()[1].getRank().toInt();

    if (secondCard == (firstCard + 1) || (firstCard == ACE && secondCard == TEN)) {
        for (int i = 2; i < ch.getAllCards().size(); ++i) {
            if (ch.getAllCards()[i].getRank().toInt() != (ch.getAllCards()[i - 1].getRank().toInt() + 1)) {
                return false;
            }
        }
        return true;
    }

    return false;
}

bool PokerScore::isFlush() {
    //std::vector<BaseCard> allCards = ch.getAllCards();
    int firstCard = ch.getAllCards()[0].getSuit().toInt();
    int secondCard = ch.getAllCards()[1].getSuit().toInt();

    if (firstCard == secondCard) {
        for (int i = 2; i < ch.getAllCards().size(); ++i) {
            if (ch.getAllCards()[i].getSuit().toInt() != firstCard) {
                return false;
            }
        }
        return true;
    }

    return false;
}

bool PokerScore::isFullHouse() {
    return maxNumber == 3 && maxUnique == 2;
}

bool PokerScore::isFourOfAKind() {
    return maxNumber == 4;
}

bool PokerScore::isStraightFlush() {
    return isStraight() && isFlush();
}

bool PokerScore::isRoyalFlush() {
    int firstValue = ch.getAllCards()[0].getRank().toInt();
    int lastValue = ch.getAllCards()[4].getRank().toInt();
    return (firstValue == ACE) && (lastValue == KING) && isStraightFlush();
}

void PokerScore::maxUniqueValue() {
    int uniqueValues = 1;

    //std::vector<BaseCard> allCards = ch.getAllCards();
    int firstValue = ch.getAllCards()[0].getRank().toInt();

    for (int i = 1; i < ch.getAllCards().size(); i++) {
        int rank = ch.getAllCards()[i].getRank().toInt();
        if (rank != firstValue) {
            uniqueValues++;
            firstValue = rank;
        }
    }

    this->maxUnique = uniqueValues;
}

void PokerScore::maxNumberOfValue() {
    int max = 1;
    int count = 1;

    //std::vector<BaseCard> allCards = ch.getAllCards();
    int firstValue = ch.getAllCards()[0].getRank().toInt();

    for (int i = 1; i < ch.getAllCards().size(); i++) {
        int rank = ch.getAllCards()[i].getRank().toInt();
        if (rank == firstValue) {
            count++;
            if (max < count) {
                max = count;
            }
        } else {
            count = 1;
            firstValue = rank;
        }
    }

    this->maxNumber = max;
}