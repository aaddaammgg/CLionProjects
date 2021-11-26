//
// Created by Adam G. on 11/23/2021.
//

#include "Screen.h"

Screen::Screen() {

}

Screen::Screen(std::string imagePath, std::string title, std::string buttonText, sf::Vector2u winSize) : button(buttonText) {
    disableState(HIDDEN);
    this->image.setTexture(ResourceHolder::getTexture(imagePath));
    text.setFont(ResourceHolder::getFont("card_font.ttf"));
    text.setCharacterSize(36);
    text.setString(title);

    this->image.setScale(.1, .1);

    sf::FloatRect tb = text.getGlobalBounds();
    sf::FloatRect ib = this->image.getGlobalBounds();
    sf::FloatRect bb = button.getGlobalBounds();

    text.setPosition(winSize.x/2 - tb.width/2, winSize.y/2 - tb.height/2);
    tb = text.getGlobalBounds();
    this->image.setPosition(winSize.x/2 - ib.width/2, tb.top + tb.height + 10);
    ib = this->image.getGlobalBounds();
    button.setPosition(winSize.x/2 - bb.width/2, ib.top + ib.height + 10);
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!isEnabled(HIDDEN)) {
        window.draw(image);
        window.draw(text);
        window.draw(button);
    }
}

void Screen::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (!isEnabled(HIDDEN)) {
        button.eventHandler(window, event);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
            if (button.getGlobalBounds().contains(mpos)) {
                enableState(HIDDEN);
            }
        }
    }
}

void Screen::update() {
    button.update();
}
