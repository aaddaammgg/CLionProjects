//
// Created by Adam G. on 10/1/2023.
//

#include "SFMLCard.h"

SFMLCard::SFMLCard() : SFMLCard(nullptr) {

}

SFMLCard::SFMLCard(BaseCard *card) {
    enableState(GUI);
    enableState(ALWAYS_ON_TOP);

    if (card != nullptr) {
        setCard(card);
    }

    setBounds({0, 0, 60, 95});
    _background.setSize({getBounds().width, getBounds().height});
    _background.setFillColor(sf::Color(200,200,200));
    _background.setCornersRadius(7);
    _background.setCornerPointCount(9);
    _background.setOutlineColor(sf::Color(0,0,0,100));
    _background.setOutlineThickness(1);

    int i = 0;
    float scale = .90;
    for (auto& back : _backOfCard) {
        back = _background;

        back.setOrigin(getBounds().width / 2, getBounds().height / 2);
        back.setPosition(getBounds().width / 2, getBounds().height / 2);
        back.setFillColor(i % 2 == 0 ? sf::Color::Black : sf::Color::Red);
        back.setScale(scale, scale);
        scale /= 1.25;
        ++i;
    }

    _cornerTopLeft.setPosition({3, 3});
    _cornerBotRight.setPosition({getBounds().width - 3, getBounds().height - 3});
    _cornerBotRight.rotate(180);

//    setOnChangeState([this](StatesENUM state) {
//        if (state == IS_HIDDEN) {
//            sf::Color col = isEnabled(state) ? sf::Color(100, 100, 100) : sf::Color(200,200,200);
//            _background.setFillColor(col);
//        }
//    });
}

BaseCard *SFMLCard::getCard() {
    return _cornerTopLeft.getCard();
}

BaseCard *SFMLCard::getCard() const {
    return _cornerTopLeft.getCard();
}

void SFMLCard::setCard(BaseCard *card) {
    _cornerTopLeft.setCard(card);
    _cornerBotRight.setCard(card);
}

void SFMLCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    if (getCard() == nullptr) {
        return;
    }

    window.draw(_background, states);

    if (isEnabled(IS_HIDDEN)) {
        for (const auto& back : _backOfCard) {
            window.draw(back, states);
        }
    } else {
        window.draw(_cornerTopLeft, states);
        window.draw(_cornerBotRight, states);
    }

}

void SFMLCard::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLCard::update(sf::RenderTarget &window) {

}
