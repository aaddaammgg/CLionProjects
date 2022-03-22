//
// Created by Adam G. on 3/21/22.
//

#include "TextInput.h"

TextInput::TextInput() {
    box.setSize(getSize());
    box.setOutlineColor(sf::Color::Green);
    box.setOutlineThickness(5);
    enableState(SELECTED);
}

void TextInput::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);
    box.setSize(size);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (isEnabled(SELECTED)) {
        typing.addEventHandler(window, event);
    }

    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect boxPos = getTransform().transformRect(box.getGlobalBounds());

    if (event.type == sf::Event::MouseButtonReleased) {
        if (boxPos.contains(mousePos)) {
            box.setOutlineColor(sf::Color::Green);
            enableState(SELECTED);
        } else {
            box.setOutlineColor(sf::Color::Red);
            disableState(SELECTED);
        }
    }

}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(box, states);
    window.draw(typing, states);
}

void TextInput::update() {
    typing.update();
}
