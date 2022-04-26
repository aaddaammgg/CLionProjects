//
// Created by Adam G. on 4/25/22.
//

#ifndef CS008_FILEIO_RESIZEABLECIRCLE_H
#define CS008_FILEIO_RESIZEABLECIRCLE_H

#include <SFML/Graphics.hpp>

class ResizeableCircle : public sf::CircleShape {
public:
    ResizeableCircle();

    void eventHandler(sf::RenderWindow &window, sf::Event event);
};


#endif //CS008_FILEIO_RESIZEABLECIRCLE_H
