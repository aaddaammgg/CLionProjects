//
// Created by Adam G. on 1/29/22.
//

#ifndef CS008_BOUNCING_OBJECTS_BOUNCINGOBJECT_H
#define CS008_BOUNCING_OBJECTS_BOUNCINGOBJECT_H

#include <SFML/Graphics.hpp>
#include "States.h"
#include <iostream>

template<class T>
class BouncingObject : public sf::Drawable, public sf::Transformable, public States {
private:
    T _shape;
    float x = 5;
    float y = 5;
    void randomFillColor();
public:
    BouncingObject();

    void bounce(sf::RenderWindow& window);
    T& shape();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};

#include "BouncingObject.cpp"

#endif //CS008_BOUNCING_OBJECTS_BOUNCINGOBJECT_H
