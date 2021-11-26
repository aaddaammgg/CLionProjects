//
// Created by Adam G. on 10/25/2021.
//

#ifndef CS3A_POKER_ANALYSIS_SFMLRANK_H
#define CS3A_POKER_ANALYSIS_SFMLRANK_H

#include <SFML/Graphics.hpp>
#include "BaseRank.h"
#include "SuitsColorENUM.h"
#include <iostream>
#include "ResourceHolder.h"

class SFMLRank : public sf::Drawable, public sf::Transformable {
private:
    BaseRank baseRank;
    sf::Text faceValueSF;
    SuitsColorENUM suitColor;
public:
    SFMLRank();
    SFMLRank(BaseRank baseRank);
    SFMLRank(RanksENUM rank);

    SuitsColorENUM getColor();

    BaseRank getRank() const;
    sf::Text getFaceValueSF();

    void setRank(RanksENUM rank);
    void setColor(SuitsColorENUM color);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS3A_POKER_ANALYSIS_SFMLRANK_H
