//
// Created by NAMEHERE on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLSUIT_H
#define CS3A_KINGS_CORNER_SFMLSUIT_H

#include <SFML/Graphics.hpp>
#include "BaseSuit.h"
#include "ResourceHolder.h"

class SFMLSuit : public sf::Drawable, public sf::Transformable {
private:
    BaseSuit baseSuit;
    sf::Sprite sprite;
    sf::FloatRect bounds;
public:
    SFMLSuit();
    SFMLSuit(BaseSuit baseSuit);
    SFMLSuit(SuitsENUM suit);

    sf::Sprite& getSprite();
    sf::FloatRect getBounds();

    BaseSuit getSuit() const;
    void setSuit(SuitsENUM suit);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS3A_KINGS_CORNER_SFMLSUIT_H
