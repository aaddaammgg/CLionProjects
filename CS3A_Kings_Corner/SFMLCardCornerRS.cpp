//
// Created by NAMEHERE on 12/3/2021.
//

#include "SFMLCardCornerRS.h"

SFMLCardCornerRS::SFMLCardCornerRS() {

}

SFMLCardCornerRS::SFMLCardCornerRS(RanksENUM rankENUM, SuitsENUM suitENUM) : rank(rankENUM), suit(suitENUM) {
    rank.setColor(static_cast<SuitsColorENUM>(suit.getSuit().getColor()));
}

void SFMLCardCornerRS::setPosition(sf::Vector2f pos) {
    suit.getSprite().setScale(.09, .09);
    sf::FloatRect rankBounds = rank.getFaceValueSF().getLocalBounds();
    sf::FloatRect suitBounds = suit.getSprite().getGlobalBounds();
    rank.setOrigin({rankBounds.width / 2, rankBounds.height / 2});
    suit.setOrigin({suitBounds.width / 2, suitBounds.height / 2});


    sf::Vector2f rankPadding = {rankBounds.width / 2, rankBounds.height / 2};
    sf::Vector2f suitPadding = {suitBounds.width / 2, suitBounds.height / 2};

    sf::Vector2f rankPos = {0, 0};

    if (isFlipped) {
        sf::Vector2f suitPos = {0, -rankBounds.height - 7};
        rank.setPosition(pos + rankPos - rankPadding);
        suit.setPosition(pos + suitPos - suitPadding);
    } else {
        sf::Vector2f suitPos = {0, rankBounds.height + 7};
        rank.setPosition(pos + rankPos + rankPadding);
        suit.setPosition(pos + suitPos + suitPadding);
    }
}

void SFMLCardCornerRS::setFlipped() {
    isFlipped = true;
    rank.rotate(180.f);
    suit.rotate(180.f);

}

void SFMLCardCornerRS::setOrigin(sf::Vector2f origin) {
    rank.setOrigin(origin);
    suit.setOrigin(origin);
}

sf::FloatRect SFMLCardCornerRS::getBounds() {
    return bounds;
}

SFMLRank SFMLCardCornerRS::getRank() const {
    return rank;
}

SFMLSuit SFMLCardCornerRS::getSuit() const {
    return suit;
}

void SFMLCardCornerRS::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(rank, states);
    window.draw(suit, states);
}
