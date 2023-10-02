//
// Created by Adam G. on 10/1/2023.
//

#include "SFMLCardCorner.h"

char SFMLCardCorner::_suits[] = {'}', '{', ']', '['};

SFMLCardCorner::SFMLCardCorner() : SFMLCardCorner(nullptr) {

}

SFMLCardCorner::SFMLCardCorner(BaseCard *card) {
    if (card != nullptr) {
        setCard(card);
    }
}

BaseCard *SFMLCardCorner::getCard() {
    return _card;
}

void SFMLCardCorner::setCard(BaseCard *card) {
    _card = card;

    sf::Color col = ((_card->getSuit().getColor() == RED) ? sf::Color(0xa33334FF) : sf::Color::Black);

    _suit.setFont(ResourceHolder::getFont("resources/fonts/cardc.ttf"));
    _suit.setString(_suits[_card->getSuit().getSuit() - 1]);
    _suit.setCharacterSize(28);
    _suit.setLetterSpacing(0);
    _suit.setFillColor(col);


    _rank.setFont(ResourceHolder::getFont("resources/fonts/cardc.ttf"));
    _rank.setString(_card->getRank().toShortString());
    _rank.setCharacterSize(28);
    _rank.setLetterSpacing(0);

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

    window.draw(_rank, states);
    window.draw(_suit, states);
}

void SFMLCardCorner::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLCardCorner::update(sf::RenderTarget &window) {

}
