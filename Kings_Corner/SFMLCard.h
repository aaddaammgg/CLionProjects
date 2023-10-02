//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_SFMLCARD_H
#define KINGS_CORNER_SFMLCARD_H

#include "GUIAdapter.h"
#include "BaseCard.h"
#include "SFMLCardCorner.h"
#include "RoundedRectangleShape.h"

class SFMLCard : public GUIAdapter {
private:
    sf::RoundedRectangleShape _background;
    SFMLCardCorner _cornerTopLeft;
    SFMLCardCorner _cornerBotRight;
public:
    SFMLCard();
    SFMLCard(BaseCard* card);

    BaseCard* getCard();
    void setCard(BaseCard* card);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_SFMLCARD_H
