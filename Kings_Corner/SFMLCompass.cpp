//
// Created by Adam G. on 10/8/2023.
//

#include "SFMLCompass.h"

SFMLCompass::SFMLCompass() {
    piles[NORTH].setPosition(0, 150);
    piles[EAST].setPosition(150, 0);
    piles[SOUTH].setPosition(0, -150);
    piles[WEST].setPosition(-150, 0);

    piles[NORTHEAST].setPosition(150, -150);
    piles[SOUTHEAST].setPosition(150, 150);
    piles[SOUTHWEST].setPosition(-150, 150);
    piles[NORTHWEST].setPosition(-150, -150);

    piles[NORTH].setRotation(180.f);
    piles[EAST].setRotation(90.f);
    piles[SOUTH].setRotation(0.f);
    piles[WEST].setRotation(-90.f);

    piles[NORTHEAST].setRotation(45.f);
    piles[SOUTHEAST].setRotation(135.f);
    piles[SOUTHWEST].setRotation(-135.f);
    piles[NORTHWEST].setRotation(-45.f);

    sfmlDeck.setDeck(&deck);

    GUIAdapter::AddComponent(&sfmlDeck);
}

void SFMLCompass::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    for (int dir = NORTH; dir != LAST_COMPASS; dir++) {
        window.draw(piles.at(static_cast<const CompassENUM>(dir)), states);
    }

//    std::cout << getTransform().transformPoint(0,0).x << std::endl; // gets me 540 WHICH IS CORRECT

    window.draw(sfmlDeck, states);
//    std::cout << sfmlDeck.getTransform().transformPoint(0,0).x << std::endl; // gets me -30  WHICH IS INCORRECT
}

void SFMLCompass::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLCompass::update(sf::RenderTarget &window) {

}
