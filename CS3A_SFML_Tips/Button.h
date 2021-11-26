//
// Created by Adam G. on 11/15/2021.
//

#ifndef CS3A_SFML_TIPS_BUTTON_H
#define CS3A_SFML_TIPS_BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.h"
#include "ResourceHolder.h"

class Button : public sf::Drawable, public States {
private:
    sf::RectangleShape background;
    sf::Text text;
    sf::Music music;
public:
    Button();
    Button(std::string text);
    Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setPosition(float x, float y);

    sf::FloatRect getGlobalBounds() const;
};


#endif //CS3A_SFML_TIPS_BUTTON_H
