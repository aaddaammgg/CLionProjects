//
// Created by NAMEHERE on 12/3/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLCARDCORNERRS_H
#define CS3A_KINGS_CORNER_SFMLCARDCORNERRS_H

#include <SFML/Graphics.hpp>
#include "SFMLRank.h"
#include "SFMLSuit.h"

class SFMLCardCornerRS : public sf::Drawable, public sf::Transformable {
private:
    SFMLRank rank;
    SFMLSuit suit;
    bool isFlipped = false;
    sf::FloatRect bounds;
public:
    SFMLCardCornerRS();
    SFMLCardCornerRS(RanksENUM rankENUM, SuitsENUM suitENUM);

    void setPosition(sf::Vector2f pos);
    void setOrigin(sf::Vector2f origin);
    void setFlipped();

    sf::FloatRect getBounds();

    SFMLRank getRank() const;
    SFMLSuit getSuit() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS3A_KINGS_CORNER_SFMLCARDCORNERRS_H
