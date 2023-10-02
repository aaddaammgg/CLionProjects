//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_SFMLCARDOUTLINE_H
#define KINGS_CORNER_SFMLCARDOUTLINE_H

#include "GUIAdapter.h"
#include "RoundedRectangleShape.h"

class SFMLCardOutline : public GUIAdapter {
private:
    sf::RoundedRectangleShape _outlinedCard;
public:
    SFMLCardOutline();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_SFMLCARDOUTLINE_H
