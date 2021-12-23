//
// Created by NAMEHERE on 11/20/2021.
//

#include "SFMLCard.h"

SFMLCard::SFMLCard() {

}

SFMLCard::SFMLCard(RanksENUM rankENUM, SuitsENUM suitENUM, bool hide) : cardCornerTopLeft(rankENUM, suitENUM), hidden(hide) {

    if (hidden) {
        setScale(.265, .265);
    }

    bounds.width = 120 / 2;
    bounds.height = 190 / 2;
    bounds.left = 0;
    bounds.top = 0;

    backCard.setTexture(ResourceHolder::getTexture("resources/images/back_of_card.png"));
    SFMLBackground.setSize({bounds.width, bounds.height});

//    SFMLBackground.setOrigin({bounds.width / 2, bounds.height / 2});
//    cardCornerTopLeft.setOrigin({bounds.width / 2, bounds.height / 2});
//    cardCornerBotRight.setOrigin({bounds.width / 2, bounds.height / 2});

    SFMLBackground.setFillColor(sf::Color(200,200,200));
//    SFMLBackground.setSize(getSize());
    SFMLBackground.setCornersRadius(7);
    SFMLBackground.setCornerPointCount(9);
    SFMLBackground.setOutlineColor(sf::Color(0,0,0,100));
    SFMLBackground.setOutlineThickness(1);

    cardCornerBotRight = cardCornerTopLeft;
    cardCornerBotRight.setFlipped();

    cardCornerTopLeft.setPosition({3, 3});

    cardCornerBotRight.setPosition({bounds.width - 3, bounds.height - 3});
}

SFMLCard::SFMLCard(RanksENUM rankENUM, SuitsENUM suitENUM) : SFMLCard(rankENUM, suitENUM, false) {

}

sf::FloatRect SFMLCard::getBounds() {
    return SFMLBackground.getGlobalBounds();
}

//void SFMLCard::setSize(sf::Vector2f cardSizeSF) {
//    this->cardSizeSF = cardSizeSF;
////    this->setPosition(cardPosSF.x, cardPosSF.y);
//}

BaseRank SFMLCard::getRank() {
    return cardCornerTopLeft.getRank().getRank();
}

BaseSuit SFMLCard::getSuit() {
    return cardCornerTopLeft.getSuit().getSuit();
}

//sf::Vector2f SFMLCard::getSize() {
//    return cardSizeSF;
//}
//
//sf::FloatRect SFMLCard::getGlobalBounds() const {
//    return this->SFMLBackground.getGlobalBounds();
//}

void SFMLCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {



    if (hidden) {
        states.transform *= getTransform();
        window.draw(backCard, states);
    } else {
        states.transform *= getTransform();
        window.draw(SFMLBackground, states);
        window.draw(cardCornerTopLeft, states);
        window.draw(cardCornerBotRight, states);
    }

}

void SFMLCard::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f newPos;
    MouseEvents::eventHandler(window, event, getTransform().transformRect(bounds), newPos);
}

void SFMLCard::update(sf::RenderWindow &window) {

}

sf::Transform SFMLCard::transform() {
    return getTransform();
}

void SFMLCard::setPosition(float x, float y) {
    Transformable::setPosition(x, y);
//    getTransform().transformPoint(0, 0).x;
//    std::cout << "x :" << getTransform().transformPoint(0, 0).x << " y: " << getTransform().transformPoint(0, 0).y << std::endl;
}

void SFMLCard::setHidden(bool val) {
    hidden = val;
//    std::cout << "hidden: " << hidden << std::endl;
    if (hidden) {
//        backCard.setScale(.28, .28);
        setScale(.28, .28);
    }
}

bool SFMLCard::isHidden() const {
    return hidden;
}

//void SFMLCard::setOrigin(float x, float y) {
//    SFMLBackground.setOrigin({x, y});
//    cardCornerTopLeft.setOrigin({x, y});
//    cardCornerBotRight.setOrigin({x, y});
//}

//void SFMLCard::setPosition(float x, float y) {
//    sf::FloatRect backgroundBounds = SFMLBackground.getGlobalBounds();
//
////    x += backgroundBounds.width / 2;
////    y += backgroundBounds.height / 2;
//
//    cardPosSF.x = x;
//    cardPosSF.y = y;
//    std::cout << "pos: " << cardPosSF.x << " " << cardPosSF.y << std::endl;
//    SFMLBackground.setPosition(cardPosSF);
//    sf::Vector2f bgtest = SFMLBackground.getPosition();
//    std::cout << "bg: " << bgtest.x << " " << bgtest.y << std::endl;
//    sf::Vector2f backgroundWH = {backgroundBounds.width / 2 - 3, backgroundBounds.height / 2 - 3};
//
//    cardCornerTopLeft.setPosition(cardPosSF - backgroundWH);
//
//    cardCornerBotRight.setPosition(cardPosSF + backgroundWH);
//}

std::ostream &operator<<(std::ostream &os, const SFMLCard &card) {
    os << "RANK: " << card.cardCornerTopLeft.getRank().getRank().toString() << " SUIT: " << card.cardCornerTopLeft.getSuit().getSuit().toString() << std::endl;

    return os;
}