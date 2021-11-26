//
// Created by Adam G. on 11/20/2021.
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

sf::Sprite SFMLSuit::getSprite() {
    return sprite;
}

void SFMLSuit::setSuit(SuitsENUM suit) {
    // SPADES = 1, HEARTS, CLUBS, DIAMONDS
    std::string s[] = {"suits/spades.png", "suits/hearts.png", "suits/clubs.png", "suits/diamonds.png"};
//    texture.loadFromFile(s[suit - 1]);
//    sprite.setTexture(texture);
    sprite.setTexture(ResourceHolder::getTexture(s[suit - 1]));
}

BaseSuit SFMLSuit::getSuit() const {
    return baseSuit;
}

void SFMLSuit::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(sprite, states);
}