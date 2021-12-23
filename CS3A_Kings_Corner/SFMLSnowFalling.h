//
// https://github.com/limepixl/falling-snow/blob/master/src/main.cpp
// Modified to fit my project

#ifndef CS3A_KINGS_CORNER_SFMLSNOWFALLING_H
#define CS3A_KINGS_CORNER_SFMLSNOWFALLING_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

class SFMLSnowFalling : public sf::Drawable {
private:
    int elapsed = 0;
    int snowFlakeCount = 200;
    int delay = 10;
    std::vector<sf::CircleShape> snowFlakes;
    void createSnowFlake();
public:
    SFMLSnowFalling();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};


#endif //CS3A_KINGS_CORNER_SFMLSNOWFALLING_H
