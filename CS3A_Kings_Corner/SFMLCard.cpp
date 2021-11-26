//
// Created by Adam G. on 11/20/2021.
//

#include "SFMLCard.h"

SFMLCard::SFMLCard() {

}

SFMLCard::SFMLCard(RanksENUM rankENUM, SuitsENUM suitENUM) : rank(rankENUM), suit(suitENUM) {
    setSize({120 / 2, 190 / 2});
    SFMLBackground.setFillColor(sf::Color(200,200,200));
    SFMLBackground.setSize(getSize());

    rank.setColor(static_cast<SuitsColorENUM>(suit.getSuit().getColor()));

}

void SFMLCard::setSize(sf::Vector2f cardSizeSF) {
    this->cardSizeSF = cardSizeSF;
    this->setPosition(cardPosSF.x, cardPosSF.y);
}

BaseRank SFMLCard::getRank() {
    return rank.getRank();
}

BaseSuit SFMLCard::getSuit() {
    return suit.getSuit();
}

sf::Vector2f SFMLCard::getSize() {
    return cardSizeSF;
}

void SFMLCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(SFMLBackground);
    window.draw(rank);
    window.draw(suit);
}

void SFMLCard::setPosition(float x, float y) {
    cardPosSF.x = x;
    cardPosSF.y = y;
    SFMLBackground.setPosition(x, y);
    suit.setScale(.035, .035);
    sf::Rect<float> rankSize = rank.getFaceValueSF().getLocalBounds();
    sf::Rect<float> suitSize = suit.getSprite().getGlobalBounds();

    sf::Vector2f rankPos = {(cardSizeSF.x / 2 - rankSize.width / 2) - 3, (cardSizeSF.y / 2 - rankSize.height - 15)};
    sf::Vector2f suitPos = {(cardSizeSF.x / 2 - (suitSize.width * suit.getScale().x) / 2), (cardSizeSF.y / 2 + 10)};

    rank.setPosition(cardPosSF + rankPos);
    suit.setPosition(cardPosSF + suitPos);

//    std::cout << "width: " << rankSize.width << " height: " << rankSize.height << std::endl;
//    std::cout << "width: " << suitSize.width << " height: " << suitSize.height << std::endl;
//    std::cout << "x: " << suit.getScale().x << " y: " << suit.getScale().y << std::endl;
}

std::ostream &operator<<(std::ostream &os, const SFMLCard &card) {
    os << "RANK: " << card.rank.getRank().toString() << " SUIT: " << card.suit.getSuit().toString() << std::endl;

    return os;
}
