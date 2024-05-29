//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_SFMLDECK_H
#define KINGS_CORNER_SFMLDECK_H

#include "MouseEvents.h"
#include "GUIAdapter.h"
#include "Deck.h"
#include "SFMLCard.h"
#include "SFMLCardOutline.h"

class SFMLDeck : public GUIAdapter {
private:
    Deck* _deck;
    SFMLCard* _dealtCard = nullptr;

    SFMLCard _topCard;
    SFMLCardOutline _cardOutline;
public:
    SFMLDeck();
    SFMLDeck(Deck* deck);

    Deck* getDeck();
    void setDeck(Deck* deck);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_SFMLDECK_H
