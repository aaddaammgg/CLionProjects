//
// Created by Adam G. on 2/26/2022.
//

#ifndef CS008_SFML_TYPING_TYPING_H
#define CS008_SFML_TYPING_TYPING_H

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

class Typing : public sf::Drawable {
private:
    sf::Text text;
    std::string str;
public:
    Typing();
    Typing(const std::string &string);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS008_SFML_TYPING_TYPING_H
