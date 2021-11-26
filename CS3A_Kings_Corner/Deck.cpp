//
// Created by Adam G. on 11/20/2021.
//

#include "Deck.h"

#include <random>

Deck::Deck() : cardIndex(0) {
    int tempIndex = 0;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 14; j++) {
            deck[tempIndex].setRank((RanksENUM)j);
            deck[tempIndex].setSuit((SuitsENUM)i);
            tempIndex++;
        }
    }
}

bool Deck::empty() {
    return cardIndex > DECK_SIZE;
}

void Deck::shuffle() {
    //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //std::shuffle(std::begin(deck), std::end(deck), std::default_random_engine(seed));
    std::random_shuffle(std::begin(deck), std::end(deck));
}

BaseCard Deck::dealCard() {
    BaseCard temp = deck[cardIndex];
    cardIndex++;
    return temp;
}

BaseCard Deck::getCardAt(int index) {
    return deck[index];
}

std::ostream &operator<<(std::ostream &os, const Deck &deck) {
    for (int i = 0; i < Deck::DECK_SIZE; i++) {
        os << i+1 << ": " << deck.deck[i] << std::endl;
    }

    return os;
}
