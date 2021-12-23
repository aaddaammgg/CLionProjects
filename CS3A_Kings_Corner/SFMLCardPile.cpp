//
// Created by NAMEHERE on 11/20/2021.
//

#include "SFMLCardPile.h"
#include <utility>

//sf::Transform SFMLCardPile::combinedTransform;

SFMLCardPile::SFMLCardPile() {
//    MouseEvents::setDraggable(true);
    bounds.width = 60;
    bounds.height = 95;
    bounds.left = 0;
    bounds.top = 0;

    setOrigin({bounds.width / 2, bounds.height / 2});
}

SFMLCardPile::SFMLCardPile(CardPile &cardPile) : cardPile(cardPile) {

//    setOrigin();

//    setCardPile(cardPile);

//    newGame(cardPile);
//    addCard(cardPile.firstCard());
//    addCard(cardPile.lastCard());

//    allCards.back().setOrigin({120 / 2, 190 / 2});

//    allCards.back().setPosition(0, 55);

//    int i = 0;
//    for (auto& card : allCards) {
//        card.setPosition(x, y + (i*(55)));
//        i++;
//    }


//    for (int i = 0; i < cardPile.getPile().getAllCards().size(); i++) {
//        SFMLCard card(cardPile.getPile().getAllCards()[i].getRank().getRank(),cardPile.getPile().getAllCards()[i].getSuit().getSuit());
//        addCard(card);
//    }
}

void SFMLCardPile::setCardPile(CardPile cPile) {
    cardPile = std::move(cPile);
    allCards.clear();

    if (cardPile.getSize() == 0)
        return;

//    std::cout << cardPile << std::endl;

    addCard(cardPile.lastCard());
    if (cardPile.getSize() >= 2) {
        addCard(cardPile.firstCard());
        allCards.front().setPosition(0, -55);
    }

    //    allCards.back().setOrigin({120 / 2, 190 / 2});


}

sf::FloatRect SFMLCardPile::getBounds() {
    return bounds;
}

CardPile& SFMLCardPile::getCardPile() {
    return cardPile;
}

std::vector<SFMLCard> SFMLCardPile::getSFMLCards() {
    return allCards;
}

void SFMLCardPile::addCard(const BaseCard& baseCard) {
    SFMLCard card(baseCard.getRank().getRank(),baseCard.getSuit().getSuit());
    allCards.push_back(card);
}

void SFMLCardPile::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    states.transform = allCards[0].getTransform();

    states.transform = getTransform();
//    states.transform *= getTransform();

//    window.draw(allCards.back(), states);

    if (outline)
        window.draw(cardOutline, states);

    if (allCards.empty())
        return;

    window.draw(allCards.back(), states);
    if (allCards.size() >= 2)
        window.draw(allCards.front(), states);


//    for (const auto& card : allCards) {
//        window.draw(card, states);
//    }
}

void SFMLCardPile::eventHandler(sf::RenderWindow &window, sf::Event event) {
//    if (allCards.empty())
//        return;


    sf::Vector2f newPos;

//    std::cout << "x: " << getTransform().transformPoint(bounds.width, bounds.height).x << " y: " << getTransform().transformPoint(0, 0).y << std::endl;
//    std::cout << "width: " << getTransform().transformRect(bounds).width << " height: " << getTransform().transformRect(bounds).height << " left: " << getTransform().transformRect(bounds).left << " top: " << getTransform().transformRect(bounds).top << std::endl;


    MouseEvents::eventHandler(window, event, getTransform().transformRect(bounds), newPos);
    if (MouseEvents::isDragging()) {
//        std::cout << "cardpile" << std::endl;
        setPosition(newPos.x, newPos.y);
    }
}

void SFMLCardPile::update(sf::RenderWindow &window) {
//    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

//    if (isClicked()) {
//        setPosition(static_cast<float>(mPos.x), static_cast<float>(mPos.y));
//    }
}

void SFMLCardPile::setOutline(bool val) {
    outline = val;
}

bool SFMLCardPile::getOutline() {
    return outline;
}

void SFMLCardPile::setOrigin(sf::Vector2f origin) {
    if (outline)
        cardOutline.setOrigin(cardOutline.getBounds().width / 2, cardOutline.getBounds().height / 2);
//    cardOutline.setOrigin(origin);
    Transformable::setOrigin(origin);
//    std::cout << "origin" << std::endl;
}

void SFMLCardPile::setPosition(float x, float y) {
    if (!init && outline) {
        cardOutline.setPosition(x, y);
        init = true;
    }

//    std::cout << "x: " << x << " y: " << y << std::endl;

    Transformable::setPosition(x, y);
//    std::cout << "x: " << getTransform().transformPoint(bounds.width, bounds.height).x << " y: " << getTransform().transformPoint(0, 0).y << std::endl;
//    std::cout << "width: " << getTransform().transformRect(bounds).width << " height: " << getTransform().transformRect(bounds).height << " left: " << getTransform().transformRect(bounds).left << " top: " << getTransform().transformRect(bounds).top << std::endl;
//    bounds.left = x;
//    bounds.top = y;
//    std::cout << "pos" << std::endl;
}

void SFMLCardPile::setRotation(float angle) {
    if (outline)
        cardOutline.setRotation(angle);

    Transformable::setRotation(angle);
}

//void SFMLCardPile::setPosition(float x, float y) {
//    int i = 0;
//    cardHandPosSF.x = x;
//    cardHandPosSF.y = y;
//    for (auto& card : allCards) {
//        card.setPosition(x, y + (i*(55)));
//        i++;
//    }
//}