//
// Created by Adam G. on 10/7/2021.
//

#include "Card.h"

Card::Card(std::string faceValue, std::string suit) : faceValue(faceValue), suit(suit) {
    setSize({300, 400});
    setPosition({50, 50});
    setFont({"card_font.ttf"});
    setBackground(sf::Color::White);
    convertSuit(suit);
    setFaceValue(faceValue);
}

Card::Card() : Card("Ace", "Hearts") {

}

void Card::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(cardBackgroundSF);
    window.draw(suitSF);
    window.draw(suit2SF);
    window.draw(faceValueSF);
}

void Card::setFont(std::string font) {
    if (!fontSF.loadFromFile(font)) {}
}

void Card::setPosition(sf::Vector2f cardPosSF) {
    this->cardPosSF = cardPosSF;
}

void Card::setSize(sf::Vector2f cardSizeSF) {
    this->cardSizeSF = cardSizeSF;
}

void Card::setIsRed(bool isRed) {
    this->isRed = isRed;
}

void Card::setBackground(sf::Color bgColor) {
    sf::RectangleShape temp;
    temp.setSize(getSize());
    temp.setPosition(getPosition());
    temp.setFillColor(bgColor);
    this->cardBackgroundSF = temp;
}

void Card::setFaceValue(std::string faceValue) {
    this->faceValue = faceValue;

    sf::Color col = (getIsRed() ? sf::Color::Red : sf::Color::Black);

    faceValueSF.setFont(fontSF);
    faceValueSF.setString(faceValue[0]);
    faceValueSF.setCharacterSize(60);
    faceValueSF.setFillColor(col);
    faceValueSF.setStyle(sf::Text::Bold);

    int charSize = faceValueSF.getCharacterSize() / 2;
    sf::Vector2f padding = {cardSizeSF.x / 2 - charSize, cardSizeSF.y / 2 - charSize};
    faceValueSF.setPosition(cardPosSF + padding);
}

void Card::setSuit(std::string suit, bool isRed) {
    this->suit = suit;
    setIsRed(isRed);

    sf::Vector2f padding(5, 5);
    sf::Vector2f imgSize = {66, 72}; // hard coded size no idea how to get the size of the sprite nor to change it (too much time wasted on this)

    sf::Vector2f topLeft(cardPosSF + padding);
    sf::Vector2f botRight(cardPosSF + cardSizeSF - padding - (imgSize));

    textureSF.loadFromFile(suit);
    suitSF.setTexture(textureSF);
    //suitSF.setTextureRect({0, 0, 66, 72});
    suitSF.setPosition(topLeft);

    suit2SF = suitSF;
    suit2SF.setPosition(botRight);
}

sf::Vector2f Card::getPosition() {
    return cardPosSF;
}

sf::Vector2f Card::getSize() {
    return cardSizeSF;
}

sf::Font Card::getFont() {
    return fontSF;
}

bool Card::getIsRed() const {
    return isRed;
}

sf::RectangleShape Card::getBackground() {
    return cardBackgroundSF;
}

std::string Card::getFaceValue() {
    return faceValue;
}

std::string Card::getSuit() {
    return suit;
}

void Card::convertSuit(std::string suitString) {
    char firstChar = std::toupper(suitString[0]);

    switch (firstChar) {
        case 'C':
            setSuit("suits/club.png", false);
            break;
        case 'D':
            setSuit("suits/diamonds.png", true);
            break;
        case 'H':
            setSuit("suits/heart.png", true);
            break;
        case 'S':
            setSuit("suits/spades.png", false);
            break;
        default:
            setSuit("suits/heart.png", true);
            break;
    }
}