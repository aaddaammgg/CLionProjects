//
// Created by Adam G. on 10/31/2021.
//

#ifndef CS3A_POKER_ANALYSIS_SFMLDRAWHANDRANK_H
#define CS3A_POKER_ANALYSIS_SFMLDRAWHANDRANK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SFMLCardHand.h"
#include "PokerScore.h"
#include "CardHandScorer.h"

class SFMLDrawHandRank : public sf::Drawable, public sf::Transformable {
private:
    SFMLCardHand sfmlCardHand;
    PokerScore::Scores pokerENUM;

    float odds;

    sf::RectangleShape background;
    sf::Text handRank;
    sf::Text probability;
    sf::Vector2f drawHandPos;
public:
    SFMLDrawHandRank();
//    SFMLDrawHandRank(PokerScore::Scores pokerENUM, PokerScore pokerScore);
    SFMLDrawHandRank(PokerScore::Scores pokerENUM, float odds);

    SFMLCardHand getSFMLCardHand();
    PokerScore::Scores getPokerENUM();
//    PokerScore getPokerScore();
    float getOdds();

    void setSFMLCardHand(SFMLCardHand sfmlCardHand);
    void setPokerENUM(PokerScore::Scores pokerENUM);
//    void setPokerScore(PokerScore pokerScore);
    void setOdds(float odds);
    void setPosition(float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS3A_POKER_ANALYSIS_SFMLDRAWHANDRANK_H
