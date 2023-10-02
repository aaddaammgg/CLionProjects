//
// Created by Adam G. on 10/1/2023.
//

#include "SFMLDeck.h"

SFMLDeck::SFMLDeck() : SFMLDeck(nullptr) {

}

SFMLDeck::SFMLDeck(Deck *deck) : _deck(deck) {

}

Deck *SFMLDeck::getDeck() {
    return _deck;
}

void SFMLDeck::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    window.draw(_cardOutline, states);

    if (_dealtCard != nullptr) {
        window.draw(*_dealtCard, states);
    }
}

void SFMLDeck::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLDeck::update(sf::RenderTarget &window) {

}
