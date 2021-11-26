//
// Created by Adam G. on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_POKERSCORE_H
#define CS3A_KINGS_CORNER_POKERSCORE_H

#include <vector>
#include "CardHand.h"
//#include "CardHandScorer.h"
#include <iostream>

class PokerScore {
public:
    enum Scores {
        ROYAL_FLUSH = 0,    //A, K, Q, J, 10, all the same suit.
        STRAIGHT_FLUSH,     //five cards of the same suit and consecutive ranking
        FOUR_OF_A_KIND,     //four cards of the same ranking
        FULL_HOUSE,         //three cards of the same rank along with two cards of the same rank
        FLUSH,              //five cards of the same suit
        STRAIGHT,           //five cards in consecutive ranking
        THREE_OF_A_KIND,    //three cards of the same rank
        TWO_PAIR,           //two cards of the same rank along with another two cards of the same rank
        ONE_PAIR,           //two cards of the same rank
        HIGH_CARD           //highest card in the player’s hand
    };
private:
    int scores[HIGH_CARD + 1] = {0};
    CardHand ch;
    int maxUnique;
    int maxNumber;
public:
    PokerScore();
    PokerScore(CardHand ch);
    int& operator[](unsigned int index);
    void operator+=(const Scores& score);
    void operator+=(const PokerScore& p);
    friend bool operator==(const PokerScore& p, Scores score);
    friend std::ostream& operator<<(std::ostream& os, const PokerScore& ps);

    static std::string scoresToString(Scores score);
    int* getScores();

    bool isHighCard();
    bool isPair();
    bool isTwoPair();
    bool isThreeOfAKind();
    bool isStraight();
    bool isFlush();
    bool isFullHouse();
    bool isFourOfAKind();
    bool isStraightFlush();
    bool isRoyalFlush();

    void maxUniqueValue();
    void maxNumberOfValue();
};


#endif //CS3A_KINGS_CORNER_POKERSCORE_H
