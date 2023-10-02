//
// Created by Adam G. on 10/1/2023.
//

#include "SFMLCard.h"

SFMLCard::SFMLCard() : SFMLCard(nullptr) {

}

SFMLCard::SFMLCard(BaseCard *card) {
    enableState(GUI);

    if (card != nullptr) {
        setCard(card);
    }

    setBounds({0, 0, 60, 95});
    _background.setSize({getBounds().width, getBounds().height});
    _background.setFillColor(sf::Color(200,200,200));
    _background.setCornersRadius(7);
    _background.setCornerPointCount(9);
    _background.setOutlineColor(sf::Color(0,0,0,100));
    _background.setOutlineThickness(1);

    _cornerTopLeft.setPosition({3, 3});
    _cornerBotRight.setPosition({getBounds().width - 3, getBounds().height - 3});
    _cornerBotRight.rotate(180);

    setOnChangeState([this](StatesENUM state) {
        if (state == IS_HIDDEN) {
            sf::Color col = isEnabled(state) ? sf::Color(100, 100, 100) : sf::Color(200,200,200);
            _background.setFillColor(col);
        }
    });
}

BaseCard *SFMLCard::getCard() {
    return _cornerTopLeft.getCard();
}

void SFMLCard::setCard(BaseCard *card) {
    _cornerTopLeft.setCard(card);
    _cornerBotRight.setCard(card);
}

void SFMLCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    window.draw(_background, states);

    if (!isEnabled(IS_HIDDEN)) {
        window.draw(_cornerTopLeft, states);
        window.draw(_cornerBotRight, states);
    }

}

void SFMLCard::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLCard::update(sf::RenderTarget &window) {

}
