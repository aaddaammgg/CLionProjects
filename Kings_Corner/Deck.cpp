//
// Created by Adam G. on 10/1/2023.
//

#include "Deck.h"

#include <random>

Deck::Deck() {
    int tempIndex = 0;

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 14; j++) {
            _deck[tempIndex].setRank((RanksENUM)j);
            _deck[tempIndex].setSuit((SuitsENUM)i);

            tempIndex++;
        }
    }

    std::cout << "new sfmlDeck" << std::endl;
}

bool Deck::empty() const {
    return _cardIndex > DECK_SIZE;
}

void Deck::shuffle() {
    std::shuffle(std::begin(_deck), std::end(_deck), std::mt19937(std::random_device()()));
    _cardIndex = 0;

    std::cout << "sfmlDeck shuffle" << std::endl;
}

BaseCard &Deck::dealCard() {
    if (empty()) {
        return _deck[0];
    }

    return _deck[_cardIndex++];
}

BaseCard &Deck::at(int index) {
    return _deck[index];
}

BaseCard &Deck::operator[](int index) {
    return at(index);
}

std::ostream &operator<<(std::ostream &os, const Deck &deck) {
    for (const auto& card : deck._deck) {
        os << card << std::endl;
    }

    return os;
}
