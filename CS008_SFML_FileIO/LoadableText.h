//
// Created by Adam G. on 4/25/22.
//

#ifndef CS008_FILEIO_LOADABLETEXT_H
#define CS008_FILEIO_LOADABLETEXT_H

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

class LoadableText : public sf::Text {
private:
    sf::Font font;
public:
    LoadableText();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
};


#endif //CS008_FILEIO_LOADABLETEXT_H
