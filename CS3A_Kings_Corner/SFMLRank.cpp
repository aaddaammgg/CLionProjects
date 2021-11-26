//
// Created by Adam G. on 11/20/2021.
//

#include "SFMLRank.h"

SFMLRank::SFMLRank() {

}

SFMLRank::SFMLRank(RanksENUM rank) : baseRank(rank) {
    setRank(rank);
}

SFMLRank::SFMLRank(BaseRank baseRank) {
    setRank(baseRank.getRank());
}

void SFMLRank::setRank(RanksENUM rank) {
   // faceValueSF.setFont(fontSF);
    faceValueSF.setFont(ResourceHolder::getFont("card_font.ttf"));
    faceValueSF.setString(getRank().toShortString());
    faceValueSF.setCharacterSize(28);

//    faceValueSF.setStyle(sf::Text::Bold);
    //faceValueSF.setPosition({20, 5});
}

BaseRank SFMLRank::getRank() const {
    return baseRank;
}

SuitsColorENUM SFMLRank::getColor() {
    return suitColor;
}

void SFMLRank::setColor(SuitsColorENUM color) {
    sf::Color col = ((color == RED) ? sf::Color::Red : sf::Color::Black);
    faceValueSF.setFillColor(col);
    this->suitColor = color;
}

sf::Text SFMLRank::getFaceValueSF() {
    return faceValueSF;
}

void SFMLRank::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(faceValueSF, states);
}
