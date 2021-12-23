//
// Created by NAMEHERE on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLBUTTON_H
#define CS3A_KINGS_CORNER_SFMLBUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.h"
#include "ResourceHolder.h"
#include "RoundedRectangleShape.h"
#include "MouseEvents.h"
#include <iostream>

class SFMLButton : public sf::Drawable, public MouseEvents {
private:
    sf::RoundedRectangleShape background;
    sf::Text text;
    sf::Sound sound;

//    sf::FloatRect bounds;
public:
    SFMLButton();
    SFMLButton(std::string text);
    SFMLButton(std::string text, sf::Color color, sf::Color textColor, unsigned int charSize);

    void setText(std::string text);
    void setFillColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setCharSize(unsigned int charSize);
    void setPosition(float x, float y);

//    sf::FloatRect getBounds();

    void updateBounds();
    bool isClicked() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    sf::FloatRect getGlobalBounds() const;
};


#endif //CS3A_KINGS_CORNER_SFMLBUTTON_H
