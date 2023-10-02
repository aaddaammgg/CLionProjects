//
// Created by Adam G. on 10/1/2023.
//

#ifndef KINGS_CORNER_SFMLCARDCORNER_H
#define KINGS_CORNER_SFMLCARDCORNER_H

#include "GUIAdapter.h"
#include "BaseCard.h"
#include "ResourceHolder.h"

class SFMLCardCorner : public GUIAdapter {
private:
    BaseCard* _card = nullptr;
    sf::Text _rank;
    sf::Text _suit;

    static char _suits[];
public:
    SFMLCardCorner();
    SFMLCardCorner(BaseCard* card);

    BaseCard* getCard();
    void setCard(BaseCard* card);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update(sf::RenderTarget& window);
};


#endif //KINGS_CORNER_SFMLCARDCORNER_H
