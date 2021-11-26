//
// Created by Adam G. on 11/23/2021.
//

#ifndef CS3A_SFML_TIPS_SCREEN_H
#define CS3A_SFML_TIPS_SCREEN_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "ResourceHolder.h"

class Screen : public sf::Drawable, public States {
private:
    sf::Text text;
    sf::Sprite image;
    Button button;
public:
    Screen();
    Screen(std::string imagePath, std::string title, std::string buttonText, sf::Vector2u winSize);

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //CS3A_SFML_TIPS_SCREEN_H
