//
// Created by NAMEHERE on 12/4/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLCOMPASS_H
#define CS3A_KINGS_CORNER_SFMLCOMPASS_H

#include <SFML/Graphics.hpp>
#include <list>
#include "FoundationCompassCards.h"
#include "SFMLCardPile.h"
#include "SFMLDeck.h"

class SFMLCompass : public sf::Drawable, public sf::Transformable {
private:
    FoundationCompassCards compassCards;
//    std::map<CompassENUM, SFMLCardPile> piles;
//    SFMLDeck deck;

    CompassENUM lastDragged = LAST_COMPASS;
    CompassENUM dropped = LAST_COMPASS;
    CompassENUM mouseReleased = LAST_COMPASS;
    CompassENUM curHover = LAST_COMPASS;

    std::list<CompassENUM> drawOrder;

    bool dragging = false;

    int isDropped = false;

    sf::FloatRect bounds;
public:
    SFMLCompass();

    FoundationCompassCards getCompassCardPiles();

    void init();

    void setPosition(sf::Vector2f pos);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};


#endif //CS3A_KINGS_CORNER_SFMLCOMPASS_H
