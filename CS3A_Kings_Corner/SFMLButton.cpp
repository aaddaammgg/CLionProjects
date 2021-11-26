//
// Created by Adam G. on 11/20/2021.
//

#include "SFMLButton.h"

SFMLButton::SFMLButton() : SFMLButton("OK", sf::Color::White, sf::Color::Blue, 30) {

}

SFMLButton::SFMLButton(std::string text) : SFMLButton(text, sf::Color::White, sf::Color::Blue, 30) {

}

SFMLButton::SFMLButton(std::string text, sf::Color color, sf::Color textColor, unsigned int charSize) {
    this->text.setFont(ResourceHolder::getFont("Roboto-Bold.ttf"));
    setTextColor(textColor);
    setCharSize(charSize);
    setText(text);

    setFillColor(color);
    background.setCornersRadius(10);
    background.setCornerPointCount(9);
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(4);

    updateBounds();

    //music.openFromFile("brap_sound.ogg");
}

void SFMLButton::updateBounds() {
    this->text.setOrigin(this->text.getLocalBounds().left, this->text.getLocalBounds().top); // https://en.sfml-dev.org/forums/index.php?topic=19004.msg137741#msg137741

    background.setOrigin(background.getLocalBounds().left, background.getLocalBounds().top);

    sf::FloatRect textBounds = this->text.getGlobalBounds();

    float mainWidth = static_cast<float>(std::max(160, static_cast<int>(textBounds.width + 40)));
    float mainHeight = static_cast<float>(50);

    background.setSize({mainWidth, mainHeight});

    float textX = mainWidth / 2 - textBounds.width / 2;
    float textY = mainHeight / 2 - textBounds.height / 2;

    this->text.setPosition(textX, textY);
}

void SFMLButton::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = background.getTransform(); // moves the text with the background
    window.draw(background);
    window.draw(text, states); // moves the text with the background
}

void SFMLButton::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if (background.getGlobalBounds().contains(mPos)) {
        if (!isEnabled(HOVERED)) {
            sf::Cursor cursor;
            if (cursor.loadFromSystem(sf::Cursor::Hand))
                window.setMouseCursor(cursor);
        }
        enableState(HOVERED);
    } else {
        if (isEnabled(HOVERED)) {
            sf::Cursor cursor;
            if (cursor.loadFromSystem(sf::Cursor::Arrow))
                window.setMouseCursor(cursor);
        }
        disableState(HOVERED);
    }
}

void SFMLButton::update() {
    if (isEnabled(HOVERED)) {

    } else {

    }
}

void SFMLButton::setText(std::string text) {
    this->text.setString(text);
}

void SFMLButton::setFillColor(sf::Color color) {
    background.setFillColor(color);
}

void SFMLButton::setTextColor(sf::Color color) {
    this->text.setFillColor(color);
}

void SFMLButton::setCharSize(unsigned int charSize) {
    this->text.setCharacterSize(charSize);
}

void SFMLButton::setPosition(float x, float y) {
    background.setPosition(x+1, y-1);
    updateBounds();
}

sf::FloatRect SFMLButton::getGlobalBounds() const {
    return background.getGlobalBounds();
}
