//
// Created by Adam G. on 12/7/2021.
//

#include "SFMLPlayerHand.h"

SFMLPlayerHand::SFMLPlayerHand() {
    bounds.width = WINDOW_WIDTH - 50;
    bounds.height = 95;
    bounds.left = 0;
    bounds.top = 0;

    bg.setSize({bounds.width, bounds.height});
    bg.setFillColor(sf::Color::Black);
    bg.setOutlineThickness(3);
    bg.setOutlineColor(sf::Color::Green);

//    bg.setOrigin({bounds.width / 2, bounds.height / 2});

    setOrigin({bounds.width / 2, bounds.height / 2});
}

void SFMLPlayerHand::addCard(const BaseCard &baseCard) {
    SFMLCard card(baseCard.getRank().getRank(),baseCard.getSuit().getSuit(), hidden);
//    card.setScale(.28, .28);
//    card.setDraggable(true);
//    card.setOrigin(card.getBounds().width / 2, card.getBounds().height / 2);


    allCards.push_back(card);
    fixCardPositions();
//    player.getCardPile().addCard(baseCard);
}

void SFMLPlayerHand::fixCardPositions() {
    int i = 0;
    int size = allCards.size();
    float totalSize = size * 65;

    for (auto& card : allCards) {
        card.setPosition((i * 65) + bounds.width / 2 - totalSize / 2 + 3, 0);
        i++;
    }
}

void SFMLPlayerHand::setCardPile(CardPile cPile) {
    player.getCardPile() = std::move(cPile);
    allCards.clear();

    if (player.getCardPile().getSize() == 0)
        return;

    for (auto card : player.getCardPile().getPile().getAllCards()) {
        addCard(card);
    }
}

void SFMLPlayerHand::setHidden(bool val) {
    hidden = val;

    if (hidden) {
        setCardPile(player.getCardPile());
//        for (auto card : allCards) {
//            card.setHidden(true);
//        }
    }
}

CardPile &SFMLPlayerHand::getCardPile() {
    return player.getCardPile();
}

std::vector<SFMLCard> SFMLPlayerHand::getSFMLCards() {
    return allCards;
}

BasePlayer &SFMLPlayerHand::getPlayer() {
    return player;
}

bool SFMLPlayerHand::isHidden() const {
    return hidden;
}

sf::FloatRect SFMLPlayerHand::getBounds() {
    return bounds;
}

void SFMLPlayerHand::setPosition(float x, float y) {
//    std::cout << "x: " << x << " y: " << y << std::endl;
//    fixCardPositions(x, y);
    Transformable::setPosition(x, y);
}

void SFMLPlayerHand::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

//    window.draw(bg, states);

    if (allCards.empty())
        return;

    for (const auto& card : allCards) {
        window.draw(card, states);
    }
}

void SFMLPlayerHand::eventHandler(sf::RenderWindow &window, sf::Event event) {
//    sf::Vector2f newPos;
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (allCards.empty()) {

        return;
    }


    for (auto card : allCards) {
        card.eventHandler(window, event);

//        std::cout << card.isHovering() << " " << card.isDraggable() << std::endl;
//        card.setPosition(mousePos.x, mousePos.y);
//        if (card.mouseButtonPressed()) {
//
//        }
//        std::cout << card.getCardPile().firstCard().getRank().toInt() << std::endl;
//        if (card.isDragging()) {
//            std::cout << newPos.x << std::endl;
//            card.setPosition(newPos.x, newPos.y);
//        }
    }
}

void SFMLPlayerHand::update(sf::RenderWindow &window) {
    int i = 0;
    int size = allCards.size();
    float totalSize = size * 65;
    sf::Vector2f pos = getPosition();

    for (auto& card : allCards) {
        card.setPosition((i * 65) + totalSize / 2 + 10 + pos.x, pos.y);
        i++;
    }
}
