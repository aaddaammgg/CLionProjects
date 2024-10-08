//
// Created by Adam G. on 1/29/22.
//

#ifndef CS008_BOUNCING_OBJECTS_BOUNCINGBALL_CPP
#define CS008_BOUNCING_OBJECTS_BOUNCINGBALL_CPP
#include "BouncingObject.h"

template<class T>
BouncingObject<T>::BouncingObject() {

}

template<class T>
T& BouncingObject<T>::shape() {
    return _shape;
}

template<class T>
void BouncingObject<T>::bounce(sf::RenderWindow& window) {
    disableState(HIT);
    const float& _x = (_shape.getPosition().x) + (x);
    const float& _y = (_shape.getPosition().y) + (y);

    const sf::FloatRect& gb = _shape.getGlobalBounds();
    const sf::Vector2u& windowSize = window.getSize();

    if (_x > (windowSize.x - gb.width) || _x < 0) {
        x = -x;
        randomFillColor(); // will enable hit
    }

    if (_y > (windowSize.y - gb.height) || _y < 0) {
        y = -y;
        randomFillColor(); // will enable hit
    }

    _shape.move(x, y);
}

template<class T>
void BouncingObject<T>::randomFillColor() {
    _shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    enableState(HIT);
}

template<class T>
void BouncingObject<T>::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_shape);
}

template<class T>
void BouncingObject<T>::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

template<class T>
void BouncingObject<T>::update(sf::RenderWindow& window) {
    std::cout << isEnabled(HIT) << std::endl;
    bounce(window);
}

#endif //CS008_BOUNCING_OBJECTS_BOUNCINGBALL_CPP