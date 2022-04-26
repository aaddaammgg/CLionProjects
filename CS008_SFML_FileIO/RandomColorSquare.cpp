//
// Created by Adam G. on 4/25/22.
//

#include "RandomColorSquare.h"

RandomColorSquare::RandomColorSquare() {
    setSize({100, 100});
}

void RandomColorSquare::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;

        setFillColor(sf::Color(r, g, b));
    }
}
