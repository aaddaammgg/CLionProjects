//
// Created by Adam G. on 2/26/2022.
//

#include "Typing.h"

Typing::Typing() : Typing("test") {

}

Typing::Typing(const std::string &string) {
    text.setFont(ResourceHolder::getFont("Roboto-Bold.ttf"));
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        switch (event.text.unicode) {
            case 8: // backspace
                if (!str.empty()) {
                    str.pop_back();
                }
                break;
            case 32 ... 128: // 32 through 128 // https://en.wikipedia.org/wiki/List_of_Unicode_characters#Control_codes
                str += static_cast<char>(event.text.unicode);
                break;
        }
        text.setString(str);
    }
}

void Typing::update() {

}
