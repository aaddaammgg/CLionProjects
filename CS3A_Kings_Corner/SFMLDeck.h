//
// Created by NAMEHERE on 12/4/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLDECK_H
#define CS3A_KINGS_CORNER_SFMLDECK_H

#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "ResourceHolder.h"
#include "MouseEvents.h"
#include "SFMLCardPile.h"

class SFMLDeck : public sf::Drawable, public MouseEvents, public sf::Transformable {
private:
    Deck deck;
    SFMLCardPile dealtCard;
    sf::Sprite sprite;
    sf::FloatRect bounds;

    bool clicked = false;
public:
    SFMLDeck();

    Deck& getDeck();
    sf::Sprite& getSprite();
    sf::FloatRect getBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS3A_KINGS_CORNER_SFMLDECK_H
