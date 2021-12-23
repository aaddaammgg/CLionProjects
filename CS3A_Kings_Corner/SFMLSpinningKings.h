//
// Created by Adam G. on 12/8/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLSPINNINGKINGS_H
#define CS3A_KINGS_CORNER_SFMLSPINNINGKINGS_H

#include <SFML/Graphics.hpp>
#include "CompassENUM.h"
#include "SFMLCard.h"

class SFMLSpinningKings : public sf::Drawable, public sf::Transformable {
private:
    std::map<CompassENUM, SFMLCard> kings;
public:
    SFMLSpinningKings();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS3A_KINGS_CORNER_SFMLSPINNINGKINGS_H
