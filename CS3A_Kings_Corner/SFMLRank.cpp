//
// Created by NAMEHERE on 11/20/2021.
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
    faceValueSF.setFont(ResourceHolder::getFont("resources/fonts/card_font.ttf"));
    faceValueSF.setString(getRank().toShortString());
    faceValueSF.setCharacterSize(28);

    bounds.width = faceValueSF.getGlobalBounds().width;
    bounds.height = faceValueSF.getGlobalBounds().height;

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
    sf::Color col = ((color == RED) ? sf::Color(0xa33334FF) : sf::Color::Black);
    faceValueSF.setFillColor(col);
    this->suitColor = color;
}

sf::FloatRect SFMLRank::getBounds() {
    return bounds;
}

sf::Text SFMLRank::getFaceValueSF() {
    return faceValueSF;
}

void SFMLRank::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(faceValueSF, states);
}
