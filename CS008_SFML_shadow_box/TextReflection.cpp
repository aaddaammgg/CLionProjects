//
// Created by Adam G. on 2/12/22.
//

#include "TextReflection.h"

TextReflection::TextReflection() : TextReflection("Test", "Roboto-Regular.ttf") {

}

TextReflection::TextReflection(const std::string &str) : TextReflection(str, "Roboto-Regular.ttf") {

}

TextReflection::TextReflection(const sf::Text &str) : TextReflection(str.getString(), "Roboto-Regular.ttf") {

}

TextReflection::TextReflection(const std::string &str, const std::string &font, unsigned int characterSize) {
    setText(str);
    setFont(font);
    setTextColor(sf::Color::White);
    setCharacterSize(characterSize);
}

std::string TextReflection::getText() {
    return text.getString();
}

sf::Color TextReflection::getTextColor() {
    return text.getFillColor();
}

void TextReflection::setText(const std::string &str) {
    text.setString(str);
    text2.setString(str);
    updatePosition();
}

void TextReflection::setTextColor(sf::Color color) {
    text.setFillColor(color);
    color.a = 50;
    text2.setFillColor(color);
}

void TextReflection::setFont(const std::string &font) {
    text.setFont(ResourceHolder::getFont(font));
    text2.setFont(ResourceHolder::getFont(font));
    updatePosition();
}

void TextReflection::setCharacterSize(unsigned int characterSize) {
    text.setCharacterSize(characterSize);
    text2.setCharacterSize(characterSize);
    updatePosition();
}

void TextReflection::setPosition(float x, float y) {
    text.setPosition(x, y);
    updatePosition();
}

void TextReflection::updatePosition() {
    sf::FloatRect textGB = text.getGlobalBounds();
    sf::FloatRect text2GB = text2.getGlobalBounds();

    text2.setScale(1, -.5);
    text2.setPosition(0, (textGB.height*2.03));

}

void TextReflection::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = text.getTransform();
    window.draw(text);
    window.draw(text2, states);
}

void TextReflection::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void TextReflection::update() {

}
