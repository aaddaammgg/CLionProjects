//
// Created by Adam G. on 2/12/22.
//

#ifndef SFML_SHADOW_BOX_TEXTREFLECTION_H
#define SFML_SHADOW_BOX_TEXTREFLECTION_H

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

class TextReflection : public sf::Drawable {
private:
    sf::Text text;
    sf::Text text2;
public:
    TextReflection();
    TextReflection(const std::string &str);
    TextReflection(const sf::Text &str);
    TextReflection(const std::string &str, const std::string &font, unsigned int characterSize=30);

    std::string getText();
    sf::Color getTextColor();

    void setText(const std::string &str);
    void setTextColor(sf::Color color);
    void setFont(const std::string &font);
    void setCharacterSize(unsigned int characterSize);
    void setPosition(float x, float y);

    void updatePosition();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_SHADOW_BOX_TEXTREFLECTION_H
