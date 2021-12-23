//
// Created by Adam G. on 12/4/2021.
//

#include "CardDetail.h"

CardDetail::CardDetail() {
    bounds.width = 100;
    bounds.height = 100;

    shape1.setSize({bounds.width, bounds.height});
    shape2.setSize({bounds.width / 2, bounds.height / 2});
    shape3.setSize({bounds.width / 4, bounds.height / 4});

    shape2.setOrigin(shape2.getSize().x / 2, shape2.getSize().y / 2);

    shape2.setPosition(bounds.width / 2, bounds.height / 2);

    shape1.setFillColor(sf::Color::Cyan);
    shape2.setFillColor(sf::Color::Magenta);
    shape3.setFillColor(sf::Color::Blue);
}

sf::FloatRect CardDetail::getBounds() {
    return bounds;
}

void CardDetail::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    window.draw(shape1, states);
    window.draw(shape2, states);
    window.draw(shape3, states);

//    window.draw(shape1);
//    window.draw(shape2);
//    window.draw(shape3);
}

void CardDetail::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void CardDetail::update() {

}
