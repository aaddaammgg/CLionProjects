//
// Created by Adam G. on 12/6/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLCARDOUTLINE_H
#define CS3A_KINGS_CORNER_SFMLCARDOUTLINE_H

#include <SFML/Graphics.hpp>
#include "RoundedRectangleShape.h"

class SFMLCardOutline : public sf::Drawable, public sf::Transformable {
private:
    sf::RoundedRectangleShape outlinedCard;

    sf::FloatRect bounds;
public:
    SFMLCardOutline();
    sf::FloatRect getBounds();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS3A_KINGS_CORNER_SFMLCARDOUTLINE_H
