//
// Created by NAMEHERE on 12/4/2021.
//

#ifndef CS3A_KINGS_CORNER_FOUNDATIONCOMPASSCARDS_H
#define CS3A_KINGS_CORNER_FOUNDATIONCOMPASSCARDS_H

#include <map>
#include "Deck.h"
#include "CompassENUM.h"
#include "CardPile.h"
#include "SFMLCardPile.h"
#include "SFMLDeck.h"
#include "SFMLGameTurnOrder.h"

class FoundationCompassCards {
private:
    SFMLDeck deck;
    SFMLGameTurnOrder turnOrder;
//    std::map<CompassENUM, CardPile> piles;

    std::map<CompassENUM, SFMLCardPile> piles;
    bool internalCombineCheck(CompassENUM dropped, CompassENUM lastDragged, int lastDragged_rank_front);
//    std::map<CompassENUM, SFMLCardOutline> cardOutlines;
//    CardPile piles[LAST_COMPASS];
public:
    FoundationCompassCards();

    Deck& getDeck();
    SFMLDeck& getSFMLDeck();
    SFMLGameTurnOrder& getSFMLGameTurnOrder();

    void shuffleDeck();

    CardPile& getPile(const CompassENUM& direction);

    void newGame();

    bool combineCheck(CompassENUM dropped, CompassENUM lastDragged);

    SFMLCardPile& operator[](CompassENUM dir);

    SFMLCardPile at(CompassENUM dir) const;


    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};


#endif //CS3A_KINGS_CORNER_FOUNDATIONCOMPASSCARDS_H
