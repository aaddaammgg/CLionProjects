//
// Created by Adam G. on 4/25/22.
//

#ifndef CS008_FILEIO_RANDOMCOLORSQUARE_H
#define CS008_FILEIO_RANDOMCOLORSQUARE_H

#include <SFML/Graphics.hpp>

class RandomColorSquare : public sf::RectangleShape {
public:
    RandomColorSquare();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
};


#endif //CS008_FILEIO_RANDOMCOLORSQUARE_H
