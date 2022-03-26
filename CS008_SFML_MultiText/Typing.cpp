//
// Created by Adam G. on 2/26/2022.
//

#include "Typing.h"

Typing::Typing() {

}

MultiText &Typing::getMultiText() {
    return mt;
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(mt, states);
}

void Typing::onTextEntered(sf::Uint32 unicode) {
    switch (unicode) {
        case 8: // backspace
            mt--;
            break;
        case 32 ... 128: // 32 through 128 // https://en.wikipedia.org/wiki/List_of_Unicode_characters#Control_codes
            mt += static_cast<char>(unicode);
            break;
        default:
            break;
    }
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIComponent::addEventHandler(window, event);
}

void Typing::update() {
    mt.update();
}
