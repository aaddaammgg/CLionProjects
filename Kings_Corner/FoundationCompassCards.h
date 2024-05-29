//
// Created by Adam G. on 10/8/2023.
//

#ifndef KINGS_CORNER_FOUNDATIONCOMPASSCARDS_H
#define KINGS_CORNER_FOUNDATIONCOMPASSCARDS_H

#include <map>
#include "Deck.h"
#include "CompassENUM.h"
#include "CardPile.h"
#include "GUIAdapter.h"
#include "SFMLCardPile.h"
#include "SFMLDeck.h"

class FoundationCompassCards : public GUIAdapter {
private:
    Deck deck;
    SFMLDeck sfmlDeck;

    std::map<CompassENUM, SFMLCardPile> piles;
public:
    FoundationCompassCards();

    Deck* getDeck();
    SFMLDeck* getSFMLDeck();
    const SFMLDeck* getSFMLDeck() const;

    CardPile* getPile(const CompassENUM& direction);

    void newGame();

    const SFMLCardPile& at(const CompassENUM& direction) const;
    SFMLCardPile& operator[](CompassENUM dir);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_FOUNDATIONCOMPASSCARDS_H
