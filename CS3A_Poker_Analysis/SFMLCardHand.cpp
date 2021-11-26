//
// Created by Adam G. on 10/31/2021.
//

#include "SFMLCardHand.h"

SFMLCardHand::SFMLCardHand() {

}

SFMLCardHand::SFMLCardHand(CardHand &cardHand) : cardHand(cardHand) {
    for (int i = 0; i < cardHand.getAllCards().size(); i++) {
        SFMLCard card(cardHand.getAllCards()[i].getRank().getRank(),cardHand.getAllCards()[i].getSuit().getSuit());
        addCard(card);
    }
}

CardHand SFMLCardHand::getCardHand() {
    return cardHand;
}

std::vector<SFMLCard> SFMLCardHand::getSFMLCards() {
    return allCards;
}

void SFMLCardHand::addCard(SFMLCard card) {
    allCards.push_back(card);
}

void SFMLCardHand::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto& card : allCards) {
        window.draw(card);
    }
}

void SFMLCardHand::setPosition(float x, float y) {
    int i = 0;
    cardHandPosSF.x = x;
    cardHandPosSF.y = y;
    for (auto& card : allCards) {
        card.setPosition((i*(card.getSize().x + 10)) + x, y);
        i++;
    }
}

sf::Vector2f SFMLCardHand::getPosition() {
    return cardHandPosSF;
}
