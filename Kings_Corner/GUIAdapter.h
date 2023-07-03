//
// Created by Quantum on 7/2/2023.
//

#ifndef KINGS_CORNER_GUIADAPTER_H
#define KINGS_CORNER_GUIADAPTER_H

#include "GUIComponent.h"
#include "MouseEvents.h"

class GUIAdapter : public GUIComponent, public MouseEvents {
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update(sf::RenderTarget& window) = 0;
};


#endif //KINGS_CORNER_GUIADAPTER_H
