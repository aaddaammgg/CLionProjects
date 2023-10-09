//
// Created by Adam G. on 10/8/2023.
//

#ifndef KINGS_CORNER_SFMLCOMPASS_H
#define KINGS_CORNER_SFMLCOMPASS_H

#include <map>
#include "GUIAdapter.h"
#include "Deck.h"
#include "CardPile.h"
#include "CompassENUM.h"
#include "SFMLCardPile.h"
#include "SFMLDeck.h"

class SFMLCompass : public GUIAdapter {
private:
    Deck deck;
    SFMLDeck sfmlDeck;

    std::map<CompassENUM, SFMLCardPile> piles;
public:
    SFMLCompass();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_SFMLCOMPASS_H
