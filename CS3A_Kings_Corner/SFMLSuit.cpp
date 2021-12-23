//
// Created by NAMEHERE on 11/20/2021.
//

#include "SFMLSuit.h"

SFMLSuit::SFMLSuit() {

}

SFMLSuit::SFMLSuit(SuitsENUM suit) : baseSuit(suit) {
    setSuit(suit);
}

SFMLSuit::SFMLSuit(BaseSuit baseSuit) {
    setSuit(baseSuit.getSuit());
}

sf::FloatRect SFMLSuit::getBounds() {
    return bounds;
}

sf::Sprite& SFMLSuit::getSprite() {
    return sprite;
}

void SFMLSuit::setSuit(SuitsENUM suit) {
    // SPADES = 1, HEARTS, CLUBS, DIAMONDS
    std::string s[] = {"resources/images/suits/spade.png", "resources/images/suits/heart.png", "resources/images/suits/club.png", "resources/images/suits/diamond.png"};
//    texture.loadFromFile(s[suit - 1]);
//    sprite.setTexture(texture);
    sprite.setTexture(ResourceHolder::getTexture(s[suit - 1]));

    bounds.width = sprite.getGlobalBounds().width;
    bounds.height = sprite.getGlobalBounds().height;
}

BaseSuit SFMLSuit::getSuit() const {
    return baseSuit;
}

void SFMLSuit::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(sprite, states);
}