//
// Created by Adam G. on 10/1/2023.
//

#include "SFMLDeck.h"

SFMLDeck::SFMLDeck() : SFMLDeck(nullptr) {

}

SFMLDeck::SFMLDeck(Deck *deck) : _deck(deck) {
    setBounds({0, 0, 60, 95});
    _topCard.enableState(IS_HIDDEN);
}

Deck *SFMLDeck::getDeck() {
    return _deck;
}

void SFMLDeck::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();

    window.draw(_cardOutline, states);
    window.draw(_topCard, states);

    if (_dealtCard != nullptr) {
        window.draw(*_dealtCard); // might have to add states back
    }
}

void SFMLDeck::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIAdapter::addEventHandler(window, event);

    // maybe switch case some way? and maybe else if
    if (MouseEvents::startedDragging() == this) {
        std::cout << "deck started dragging" << std::endl;

        _dealtCard = new SFMLCard(&_deck->dealCard());
//        GUIAdapter::components.push_front(_dealtCard);
    }
    if (MouseEvents::selected == this && MouseEvents::isDragging() && _dealtCard != nullptr) {
//        std::cout << "deck dragging" << std::endl;

        sf::Vector2f dimensions = {_dealtCard->getBounds().width / 2, _dealtCard->getBounds().height / 2};
        _dealtCard->setPosition(MouseEvents::currentMousePos - dimensions);
    }
    if (MouseEvents::lastSelected == this && MouseEvents::mouseButtonReleased(false)) {
        std::cout << "deck released" << std::endl;
    }
    if (MouseEvents::dragAndDrop() == this) {
        std::cout << "deck drag n drop" << std::endl;
//        auto it = std::find(GUIAdapter::components.begin(), GUIAdapter::components.end(), _dealtCard);
//
//        if (it != GUIAdapter::components.end()) {
//            GUIAdapter::components.erase(it);
//        }

//        GUIAdapter::components.p

        SFMLCard* temp = _dealtCard;

//        delete _dealtCard;
        _dealtCard = nullptr;

        delete temp;
    }
}

void SFMLDeck::update(sf::RenderTarget &window) {

}
