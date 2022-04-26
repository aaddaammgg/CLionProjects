//
// Created by Adam G. on 4/25/22.
//

#include "ResizeableCircle.h"

ResizeableCircle::ResizeableCircle() {
    setRadius(50);
    setOrigin(50, 50);
}

void ResizeableCircle::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if (getGlobalBounds().contains(mPos) && sf::Event::MouseMoved == event.type) {
            setRadius(mPos.y);
        }
    }
}
