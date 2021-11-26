//
// Created by Adam G. on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLDRAWALLHANDRANKINGS_H
#define CS3A_KINGS_CORNER_SFMLDRAWALLHANDRANKINGS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SFMLDrawHandRank.h"
#include "PokerScore.h"

class SFMLDrawAllHandRankings : public sf::Drawable, public sf::Transformable {
private:
    PokerScore pokerScore;
    std::vector<SFMLDrawHandRank> handRanks;
public:
    SFMLDrawAllHandRankings();
    SFMLDrawAllHandRankings(PokerScore pokerScore);

    PokerScore getPokerScore();
    std::vector<SFMLDrawHandRank> getHandRanks();

    void setPokerScore(PokerScore pokerScore);
    void setHandRanks(std::vector<SFMLDrawHandRank> handRanks);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS3A_KINGS_CORNER_SFMLDRAWALLHANDRANKINGS_H
