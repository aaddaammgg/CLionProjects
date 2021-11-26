//
// Created by Adam G. on 11/20/2021.
//

#include "CardHandScorer.h"

CardHandScorer::CardHandScorer() {

}

//PokerScore CardHandScorer::scorePokerHand(CardHand ch, bool &noRoyalFlush) {
//    PokerScore ps(ch);
//
//    if (ps.isRoyalFlush()){
//        ps += PokerScore::ROYAL_FLUSH;
//        noRoyalFlush = false;
//    }
//
//    if (ps.isStraightFlush())
//        ps += PokerScore::STRAIGHT_FLUSH;
//    if (ps.isFourOfAKind())
//        ps += PokerScore::FOUR_OF_A_KIND;
//    if (ps.isFullHouse())
//        ps += PokerScore::FULL_HOUSE;
//    if (ps.isFlush())
//        ps += PokerScore::FLUSH;
//    if (ps.isStraight())
//        ps += PokerScore::STRAIGHT;
//    if (ps.isThreeOfAKind())
//        ps += PokerScore::THREE_OK_A_KIND;
//    if (ps.isTwoPair())
//        ps += PokerScore::TWO_PAIR;
//    if (ps.isPair())
//        ps += PokerScore::ONE_PAIR;
//
//    ps += PokerScore::HIGH_CARD;
//
//    return ps;
//}

PokerScore CardHandScorer::scorePokerHand(CardHand ch, bool &noRoyalFlush) {
    ch.sort();
    PokerScore ps(ch);
    if (ps.isRoyalFlush()){
        ps += PokerScore::ROYAL_FLUSH;
        ps += PokerScore::STRAIGHT_FLUSH;
        ps += PokerScore::FLUSH;
        ps += PokerScore::STRAIGHT;
        std::cout << "We got a RF!!\n";
        noRoyalFlush = false;
    }

   else if (ps.isStraightFlush())
    {
        ps += PokerScore::STRAIGHT_FLUSH;
        ps += PokerScore::FLUSH;
        ps += PokerScore::STRAIGHT;
    }

    else if (ps.isFourOfAKind())
    {
        ps += PokerScore::FOUR_OF_A_KIND;
        ps += PokerScore::TWO_PAIR;
        ps += PokerScore::THREE_OF_A_KIND;
        ps += PokerScore::ONE_PAIR;
    }

    else if (ps.isFullHouse())
    {
        ps += PokerScore::FULL_HOUSE;
        ps += PokerScore::TWO_PAIR;
        ps += PokerScore::THREE_OF_A_KIND;
        ps += PokerScore::ONE_PAIR;

    }

   else  if (ps.isFlush())
    {
        ps += PokerScore::FLUSH;
    }
   else  if (ps.isStraight())
        ps += PokerScore::STRAIGHT;
    else if (ps.isThreeOfAKind())
    {
        ps += PokerScore::THREE_OF_A_KIND;
        ps += PokerScore::TWO_PAIR;
        ps += PokerScore::ONE_PAIR;
    }

   else if (ps.isTwoPair())
        ps += PokerScore::TWO_PAIR;
    else if (ps.isPair())
        ps += PokerScore::ONE_PAIR;

    ps += PokerScore::HIGH_CARD;

    return ps;
}