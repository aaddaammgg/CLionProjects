//
// Created by Adam G. on 11/15/2021.
//

#include "Button.h"

Button::Button() : Button("OK", sf::Color::White, sf::Color::Blue, {100, 50}) {

}

Button::Button(std::string text) : Button(text, sf::Color::White, sf::Color::Blue, {100, 50}) {

}

Button::Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size) {
    this->text.setFont(ResourceHolder::getFont("card_font.ttf"));
    this->text.setFillColor(textColor);
    this->text.setString(text);
    background.setSize(size);
    background.setFillColor(color);

    sf::FloatRect tb = this->text.getGlobalBounds();
    sf::FloatRect bb = background.getGlobalBounds();

    this->text.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height);
    music.openFromFile("brap_sound.ogg");
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = background.getTransform(); // moves the text with the background
    window.draw(background);
    window.draw(text, states); // moves the text with the background
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if (background.getGlobalBounds().contains(mpos)) {
        enableState(HOVERED);
    } else {
        disableState(HOVERED);
    }
}

void Button::update() {
    if (isEnabled(HIDDEN)) return;
    if (isEnabled(HOVERED)) {
        background.setFillColor(sf::Color::Yellow);
        if (music.getStatus() != sf::SoundSource::Status::Playing) {
            music.play();
            music.setLoop(true);
        }

    } else {
        background.setFillColor(sf::Color::White);
        music.stop();
    }
}

void Button::setPosition(float x, float y) {
    background.setPosition(x, y);
}

sf::FloatRect Button::getGlobalBounds() const {
    return background.getGlobalBounds();
}
