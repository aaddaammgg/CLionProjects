//
// Created by Adam G. on 12/4/2021.
//

#include <iostream>
#include "Card.h"

Card::Card() {
    bounds.width = 300;
    bounds.height = 300;

    shape1.setSize({bounds.width, bounds.height});
    shape2.setSize({bounds.width / 2, bounds.height / 2});
    shape3.setSize({bounds.width / 4, bounds.height / 4});

    shape2.setOrigin(shape2.getSize().x / 2, shape2.getSize().y / 2);
    cd.setOrigin(cd.getBounds().width, cd.getBounds().height);


    cd.setPosition(bounds.width, bounds.height);
    std::cout << cd.getPosition().x << " " << cd.getPosition().y << std::endl;
    std::cout << cd.getPosition().x << " " << cd.getPosition().y << std::endl;
    shape2.setPosition(bounds.width / 2, bounds.height / 2);

    shape2.setFillColor(sf::Color::Red);
    shape3.setFillColor(sf::Color::Green);
}

sf::FloatRect Card::getBounds() {
    return bounds;
}

void Card::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    states.transform = getTransform();

    window.draw(shape1, states);
    window.draw(shape2, states);
    window.draw(shape3, states);
    window.draw(cd, states);
}

void Card::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Card::update() {

}
