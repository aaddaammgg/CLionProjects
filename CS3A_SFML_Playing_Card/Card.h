//
// Created by Adam G. on 10/7/2021.
//

#ifndef CS3A_SFML_PLAYING_CARD_CARD_H
#define CS3A_SFML_PLAYING_CARD_CARD_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Card : public sf::Drawable, sf::Transformable {

private:
    std::string faceValue;
    std::string suit;
    bool isRed;

    sf::Font fontSF;
    sf::Vector2f cardPosSF;
    sf::Vector2f cardSizeSF;
    sf::RectangleShape cardBackgroundSF;
    sf::Text faceValueSF;
    sf::Sprite suitSF;
    sf::Sprite suit2SF;
    sf::Texture textureSF;

public:
    Card(std::string faceValue, std::string suit);
    Card();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

    void setFont(std::string font);
    void setPosition(sf::Vector2f cardPos);
    void setSize(sf::Vector2f cardSizeSF);
    void setIsRed(bool isRed);
    void setBackground(sf::Color bgColor);
    void setFaceValue(std::string faceValue);
    void setSuit(std::string suit, bool isRed);

    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Font getFont();
    sf::RectangleShape getBackground();
    std::string getFaceValue();
    std::string getSuit();
    bool getIsRed() const;

    void convertSuit(std::string suitString);

};


#endif //CS3A_SFML_PLAYING_CARD_CARD_H
