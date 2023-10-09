//
// Created by Adam G. on 10/8/2023.
//

#ifndef KINGS_CORNER_SFMLCARDPILE_H
#define KINGS_CORNER_SFMLCARDPILE_H

#include <vector>
#include "GUIAdapter.h"
#include "SFMLCardOutline.h"
#include "SFMLCard.h"
#include "CardPile.h"

class SFMLCardPile : public GUIAdapter, public CardPile {
private:
    SFMLCardOutline _cardOutline;
    SFMLCard _cards[2];
public:
    SFMLCardPile();

    virtual void addCard(BaseCard* card);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_SFMLCARDPILE_H
