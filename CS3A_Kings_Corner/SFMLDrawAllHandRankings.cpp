//
// Created by Adam G. on 11/20/2021.
//

#include "SFMLDrawAllHandRankings.h"

SFMLDrawAllHandRankings::SFMLDrawAllHandRankings() {

}

SFMLDrawAllHandRankings::SFMLDrawAllHandRankings(PokerScore pokerScore) : pokerScore(pokerScore) {
    for (int i = 0; i < PokerScore::Scores::HIGH_CARD + 1; i++) {
        float probability = (float)1 / ((float)pokerScore.getScores()[i] / (float)pokerScore.getScores()[PokerScore::Scores::HIGH_CARD]);
        SFMLDrawHandRank s1(static_cast<PokerScore::Scores>(i), probability);
        float x = 10;
        float y = (i*190) + 10;
        if (i > 4) {
            x = 400;
            y = ((i-5)*190) + 10;
        }
        s1.setPosition(x, y);
        handRanks.push_back(s1);
    }
}

std::vector<SFMLDrawHandRank> SFMLDrawAllHandRankings::getHandRanks() {
    return handRanks;
}

PokerScore SFMLDrawAllHandRankings::getPokerScore() {
    return pokerScore;
}

void SFMLDrawAllHandRankings::setPokerScore(PokerScore pokerScore) {
    this->pokerScore = pokerScore;
}

void SFMLDrawAllHandRankings::setHandRanks(std::vector<SFMLDrawHandRank> handRanks) {
    this->handRanks = handRanks;
}

void SFMLDrawAllHandRankings::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();

    for (auto& handRank : handRanks) {
        window.draw(handRank);
    }
}
