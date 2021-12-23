//
// Created by Adam G. on 12/7/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLGAMETURNORDER_H
#define CS3A_KINGS_CORNER_SFMLGAMETURNORDER_H

#include <map>
#include "DEFINITIONS.h"
#include "SFMLPlayerHand.h"
#include "Deck.h"

class SFMLGameTurnOrder : public sf::Drawable, public sf::Transformable {
private:
    std::map<int, SFMLPlayerHand> players;
    int curPlayer = 1;
    void deal7Cards(int index, Deck& deck);
public:
    SFMLGameTurnOrder();

    SFMLPlayerHand& getPlayerAt(int index);
    int getCurPlayer() const;

    int addPlayer(Deck& deck);
    void nextPlayer();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};


#endif //CS3A_KINGS_CORNER_SFMLGAMETURNORDER_H
