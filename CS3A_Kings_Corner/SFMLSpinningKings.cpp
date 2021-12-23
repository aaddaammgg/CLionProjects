//
// Created by Adam G. on 12/8/2021.
//

#include "SFMLSpinningKings.h"

SFMLSpinningKings::SFMLSpinningKings() {
    kings[NORTHEAST] = SFMLCard(KING, SPADES);
    kings[SOUTHEAST] = SFMLCard(KING, HEARTS);
    kings[SOUTHWEST] = SFMLCard(KING, CLUBS);
    kings[NORTHWEST] = SFMLCard(KING, DIAMONDS);

    kings[NORTHEAST].setRotation(135.f);
    kings[SOUTHEAST].setRotation(45.f);
    kings[SOUTHWEST].setRotation(-45.f);
    kings[NORTHWEST].setRotation(-135.f);

    kings[NORTHEAST].setOrigin(kings[NORTHEAST].getBounds().width / 2, kings[NORTHEAST].getBounds().height / 2);
    kings[SOUTHEAST].setOrigin(kings[NORTHEAST].getBounds().width / 2, kings[NORTHEAST].getBounds().height / 2);
    kings[SOUTHWEST].setOrigin(kings[NORTHEAST].getBounds().width / 2, kings[NORTHEAST].getBounds().height / 2);
    kings[NORTHWEST].setOrigin(kings[NORTHEAST].getBounds().width / 2, kings[NORTHEAST].getBounds().height / 2);

    float padding = 115;

    kings[NORTHEAST].setPosition(padding, padding);
    kings[SOUTHEAST].setPosition(padding, -padding);
    kings[SOUTHWEST].setPosition(-padding, -padding);
    kings[NORTHWEST].setPosition(-padding, padding);
//    kings[SOUTHEAST].setOrigin(kings[NORTHEAST].getBounds().width / 2, kings[NORTHEAST].getBounds().height / 2);
//    kings[SOUTHWEST].setOrigin(kings[NORTHEAST].getBounds().width / 2, kings[NORTHEAST].getBounds().height / 2);
//    kings[NORTHWEST].setOrigin(kings[NORTHEAST].getBounds().width / 2, kings[NORTHEAST].getBounds().height / 2);

}

void SFMLSpinningKings::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    for (auto king : kings) {
        window.draw(king.second, states);
    }
}

void SFMLSpinningKings::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLSpinningKings::update() {
    rotate(.5);
}
