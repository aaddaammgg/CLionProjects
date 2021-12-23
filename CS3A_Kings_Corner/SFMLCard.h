//
// Created by NAMEHERE on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLCARD_H
#define CS3A_KINGS_CORNER_SFMLCARD_H

#include <SFML/Graphics.hpp>
#include "SFMLRank.h"
#include "SFMLSuit.h"
#include "SFMLCardCornerRS.h"
#include "RoundedRectangleShape.h"
#include "MouseEvents.h"
#include <iostream>

class SFMLCard : public sf::Drawable, public sf::Transformable, public MouseEvents {
private:
    sf::RoundedRectangleShape SFMLBackground;
    SFMLCardCornerRS cardCornerTopLeft;
    SFMLCardCornerRS cardCornerBotRight;
    sf::Sprite backCard;

    bool hidden = false;

    sf::FloatRect bounds;
public:
    SFMLCard();
    SFMLCard(RanksENUM rankENUM, SuitsENUM suitENUM);
    SFMLCard(RanksENUM rankENUM, SuitsENUM suitENUM, bool hide);

    void setHidden(bool val);
    bool isHidden() const;

//    void setSize(sf::Vector2f cardSizeSF);
    void setPosition(float x, float y);
//    void setOrigin(float x, float y);

    sf::FloatRect getBounds();
    sf::Transform transform();

//    sf::Vector2f getSize();

    BaseRank getRank();
    BaseSuit getSuit();

//    sf::FloatRect getGlobalBounds() const;


    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
    friend std::ostream& operator<<(std::ostream& os, const SFMLCard& card);

};


#endif //CS3A_KINGS_CORNER_SFMLCARD_H
