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
    window.draw(mt, states);

}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        switch (event.text.unicode) {
            case 8: // backspace
                mt--;
                break;
            case 32 ... 128: // 32 through 128 // https://en.wikipedia.org/wiki/List_of_Unicode_characters#Control_codes
                mt += static_cast<char>(event.text.unicode);
                break;
        }
    }
}

void Typing::update() {
    mt.update();
}
