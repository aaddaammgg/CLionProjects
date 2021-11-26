//
// Created by Adam G. on 10/25/2021.
//

#ifndef CS3A_POKER_ANALYSIS_SFMLCARD_H
#define CS3A_POKER_ANALYSIS_SFMLCARD_H

#include <SFML/Graphics.hpp>
#include "SFMLBackground.h"
#include "SFMLRank.h"
#include "SFMLSuit.h"
#include <iostream>

class SFMLCard : public sf::Drawable {
private:
    SFMLBackground SFMLBackground;
    SFMLRank rank;
    SFMLSuit suit;

    sf::Vector2f cardPosSF;
    sf::Vector2f cardSizeSF;
public:
    SFMLCard();
    SFMLCard(RanksENUM rankENUM, SuitsENUM suitENUM);

    void setSize(sf::Vector2f cardSizeSF);
    sf::Vector2f getSize();

    BaseRank getRank();
    BaseSuit getSuit();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
    friend std::ostream& operator<<(std::ostream& os, const SFMLCard& card);
};


#endif //CS3A_POKER_ANALYSIS_SFMLCARD_H
