//
// Created by Adam G. on 10/1/2023.
//

#include "SFMLCardOutline.h"

SFMLCardOutline::SFMLCardOutline() {
    setBounds({0, 0, CARD_WIDTH, CARD_HEIGHT});

    _outlinedCard.setSize({getLocalBounds().width, getLocalBounds().height});

    _outlinedCard.setFillColor(sf::Color(0,0,0,150));
    _outlinedCard.setCornersRadius(7);
    _outlinedCard.setCornerPointCount(9);

    _outlinedCard.setOutlineColor(sf::Color(0,0,0,100));
    _outlinedCard.setOutlineThickness(5);
}

void SFMLCardOutline::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(_outlinedCard, states);
}

void SFMLCardOutline::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLCardOutline::update(sf::RenderTarget &window) {

}
