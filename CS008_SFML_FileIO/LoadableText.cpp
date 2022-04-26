//
// Created by Adam G. on 4/25/22.
//

#include "LoadableText.h"

LoadableText::LoadableText() {
    setFont(ResourceHolder::getFont("Roboto-Regular.ttf"));
}

void LoadableText::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Event::TextEntered == event.type) {
        std::string str = getString();
        str += char(event.text.unicode);
        setString(str);
    }
}
