//
// Created by Adam G. on 10/8/2023.
//

#include "FoundationCompassCards.h"

FoundationCompassCards::FoundationCompassCards() {
    sfmlDeck.setDeck(&deck);
}

Deck *FoundationCompassCards::getDeck() {
    return &deck;
}

SFMLDeck *FoundationCompassCards::getSFMLDeck() {
    return &sfmlDeck;
}

const SFMLDeck *FoundationCompassCards::getSFMLDeck() const {
    return &sfmlDeck;
}

CardPile *FoundationCompassCards::getPile(const CompassENUM &direction) {
    return &piles.at(direction);
}

void FoundationCompassCards::newGame() {

}

const SFMLCardPile &FoundationCompassCards::at(const CompassENUM &direction) const {
    return piles.at(direction);
}

SFMLCardPile &FoundationCompassCards::operator[](CompassENUM dir) {
    return piles[dir];
}

void FoundationCompassCards::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    window.draw(sfmlDeck, states);
}

void FoundationCompassCards::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void FoundationCompassCards::update(sf::RenderTarget &window) {

}
