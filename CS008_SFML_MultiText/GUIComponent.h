//
// Created by Adam G. on 3/21/22.
//

#ifndef CS008_SFML_TYPING_GUICOMPONENT_H
#define CS008_SFML_TYPING_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "States.h"

class GUIComponent : public sf::Drawable, public sf::Transformable, public States {
private:
    sf::Vector2f size;
public:
    GUIComponent();

    sf::Vector2f getSize();
    void setSize(sf::Vector2f size);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //CS008_SFML_TYPING_GUICOMPONENT_H
