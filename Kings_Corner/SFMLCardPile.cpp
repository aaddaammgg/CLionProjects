//
// Created by Adam G. on 10/8/2023.
//

#include "SFMLCardPile.h"

SFMLCardPile::SFMLCardPile() {
    setBounds({0, 0, CARD_WIDTH, CARD_HEIGHT});
    setOrigin({getLocalBounds().width / 2, getLocalBounds().height / 2});
    _cards[1].setPosition(0, 60);
}

void SFMLCardPile::addCard(BaseCard *card) {
    CardHand::addCard(card);

    _cards[0].setCard(firstCard());

    if (getPileSize() > 1) {
        _cards[1].setCard(lastCard());
    }
}

void SFMLCardPile::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    window.draw(_cardOutline, states);

    for (auto card : _cards) {
        if (card.getCard() != nullptr) {
            window.draw(card, states);
        }
    }
}

void SFMLCardPile::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLCardPile::update(sf::RenderTarget &window) {

}
