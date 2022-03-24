//
// Created by Adam G. on 3/21/22.
//

#include "TextInput.h"

TextInput::TextInput() {
    box.setSize(getSize());
    box.setOutlineColor(sf::Color::Green);
    box.setOutlineThickness(5);

    cursorBlink.setPosition(1, 1);
    typing.setPosition(0, -2);

    enableState(SELECTED);
    cursorBlink.enableState(SELECTED);
}

void TextInput::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);
    box.setSize(size);
    cursorBlink.setSize({2, size.y - 2});
    typing.getMultiText().setCharacterSize(static_cast<unsigned int>(size.y));
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (isEnabled(SELECTED)) {
        typing.addEventHandler(window, event);

        if (event.type == sf::Event::TextEntered) {
            if (typing.getMultiText().isEmpty()) {
                cursorBlink.setPosition({1, 1});
            } else {
                sf::Vector2f curPos = typing.getMultiText().back().getPosition();
                sf::FloatRect backBounds = typing.getMultiText().back().getLocalBounds();

                curPos += {1, 1};
                curPos += {backBounds.width + backBounds.left + 1, 0};

                cursorBlink.setPosition(curPos);
            }
        }
    }

    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect boxPos = getTransform().transformRect(box.getGlobalBounds());

    if (event.type == sf::Event::MouseButtonReleased) {
        if (boxPos.contains(mousePos)) {
            box.setOutlineColor(sf::Color::Green);
            enableState(SELECTED);
            cursorBlink.enableState(SELECTED);
        } else {
            box.setOutlineColor(sf::Color::Red);
            disableState(SELECTED);
            cursorBlink.disableState(SELECTED);
        }
    }

}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(box, states);
    window.draw(typing, states);
    window.draw(cursorBlink, states);
}

void TextInput::update() {
    typing.update();
    cursorBlink.update();
}
