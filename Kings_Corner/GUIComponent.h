//
// Created by Quantum on 5/13/2023.
//

#ifndef KINGS_CORNER_GUICOMPONENT_H
#define KINGS_CORNER_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "States.h"

class GUIComponent : public sf::Drawable, public sf::Transformable, public States {
private:
    sf::FloatRect _bounds;
public:
    GUIComponent() = default;

    sf::FloatRect getBounds();
    void setBounds(sf::FloatRect bounds);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //KINGS_CORNER_GUICOMPONENT_H
