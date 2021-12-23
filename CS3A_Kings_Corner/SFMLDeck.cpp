//
// Created by NAMEHERE on 12/4/2021.
//

#include "SFMLDeck.h"

SFMLDeck::SFMLDeck() {
    MouseEvents::setDraggable(true);
    sprite.setTexture(ResourceHolder::getTexture("resources/images/back_of_card.png"));

    setScale(.265, .265);

    bounds.width = sprite.getGlobalBounds().width;
    bounds.height = sprite.getGlobalBounds().height;

    setOrigin(bounds.width / 2, bounds.height / 2);

    dealtCard.setOutline(false);


//    bounds.width = sprite.getGlobalBounds().width;
//    bounds.height = sprite.getGlobalBounds().height;
}

Deck& SFMLDeck::getDeck() {
    return deck;
}

sf::Sprite &SFMLDeck::getSprite() {
    return sprite;
}

sf::FloatRect SFMLDeck::getBounds() {
    return bounds;
}

void SFMLDeck::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    states.transform = getTransform();
    window.draw(sprite, states);
    window.draw(dealtCard, states);
}

void SFMLDeck::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f newPos;
    MouseEvents::eventHandler(window, event, getTransform().transformRect(bounds), newPos);

    if (MouseEvents::mouseButtonPressed() && MouseEvents::isDragging() && !clicked) {
        std::cout << "pressed deck" << std::endl;

        BaseCard bc = getDeck().dealCard();

        std::cout << bc << std::endl;

        CardPile cp;
        cp.addCard(bc);
        dealtCard.setCardPile(cp);

        clicked = true;
    }

    if (MouseEvents::mouseButtonReleased(false)) {
        std::cout << "released deck" << std::endl;
        clicked = false;
    }

    if (MouseEvents::isDragging()) {
        std::cout << "draggin card" << std::endl;
        dealtCard.setPosition(newPos.x, newPos.y);
//        setPosition(newPos.x, newPos.y);
    }
}

void SFMLDeck::update() {

}
