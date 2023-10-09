//
// Created by Adam G. on 10/1/2023.
//

#include "SFMLCardCorner.h"

char SFMLCardCorner::_suits[] = {'}', '{', ']', '['};

SFMLCardCorner::SFMLCardCorner() : SFMLCardCorner(nullptr) {

}

SFMLCardCorner::SFMLCardCorner(BaseCard *card) {
    setCard(card);

    _rank.setFont(ResourceHolder::getFont("resources/fonts/cardc.ttf"));
    _rank.setCharacterSize(28);
    _rank.setLetterSpacing(0);

    _suit.setFont(ResourceHolder::getFont("resources/fonts/cardc.ttf"));
    _suit.setCharacterSize(28);
    _suit.setLetterSpacing(0);
}

BaseCard *SFMLCardCorner::getCard() {
    return _card;
}

BaseCard *SFMLCardCorner::getCard() const {
    return _card;
}

void SFMLCardCorner::setCard(BaseCard *card) {
    _card = card;

    if (_card == nullptr) {
        return;
    }

    sf::Color col = ((_card->getSuit().getColor() == RED) ? sf::Color(0xa33334FF) : sf::Color::Black);

    _suit.setString(_suits[_card->getSuit().getSuit() - 1]);
    _suit.setFillColor(col);

    _rank.setString(_card->getRank().toShortString());
    _rank.setFillColor(col);

    sf::FloatRect rankBounds = _rank.getLocalBounds();

    _suit.setPosition(-2, rankBounds.height + 5);

    sf::FloatRect suitBounds = _suit.getLocalBounds();
    sf::Vector2f suitPos = _suit.getPosition();

    sf::FloatRect bounds = {0, 0, rankBounds.width, suitPos.y + suitBounds.height};

    setBounds(bounds);
}

void SFMLCardCorner::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    if (_card != nullptr) {
        window.draw(_rank, states);
        window.draw(_suit, states);
    }
}

void SFMLCardCorner::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLCardCorner::update(sf::RenderTarget &window) {

}
