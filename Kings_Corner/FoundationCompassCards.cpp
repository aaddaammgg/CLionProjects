//
// Created by Adam G. on 10/8/2023.
//

#include "FoundationCompassCards.h"

FoundationCompassCards::FoundationCompassCards() {

}

Deck *FoundationCompassCards::getDeck() {
    return deck.getDeck();
}

SFMLDeck *FoundationCompassCards::getSFMLDeck() {
    return &deck;
}

CardPile *FoundationCompassCards::getPile(const CompassENUM &direction) {
    return &piles.at(direction);
}

void FoundationCompassCards::newGame() {

}

void FoundationCompassCards::draw(sf::RenderTarget &window, sf::RenderStates states) const {

}

void FoundationCompassCards::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void FoundationCompassCards::update(sf::RenderTarget &window) {

}
