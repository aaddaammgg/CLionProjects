//
// Created by Quantum on 7/2/2023.
//

#ifndef KINGS_CORNER_GUI_CIRCLE_H
#define KINGS_CORNER_GUI_CIRCLE_H

#include "GUIAdapter.h"

class GUI_Circle : public GUIAdapter {
private:
    sf::CircleShape circle;
public:
    GUI_Circle(sf::Color color);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_GUI_CIRCLE_H
