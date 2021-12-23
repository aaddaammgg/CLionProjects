//
// Created by Adam G. on 12/4/2021.
//

#ifndef CS3A_SFML_ROTATETEST_CARD_H
#define CS3A_SFML_ROTATETEST_CARD_H

#include <SFML/Graphics.hpp>
#include "CardDetail.h"

class Card : public sf::Drawable, public sf::Transformable {
private:
    sf::RectangleShape shape1;
    sf::RectangleShape shape2;
    sf::RectangleShape shape3;

    sf::FloatRect bounds;
    CardDetail cd;
public:
    Card();

    sf::FloatRect getBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS3A_SFML_ROTATETEST_CARD_H
