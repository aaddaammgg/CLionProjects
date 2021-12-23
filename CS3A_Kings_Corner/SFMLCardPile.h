//
// Created by NAMEHERE on 11/20/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLCARDPILE_H
#define CS3A_KINGS_CORNER_SFMLCARDPILE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SFMLCard.h"
#include "CardPile.h"
#include "MouseEvents.h"
#include "States.h"
#include "SFMLCardOutline.h"

class SFMLCardPile : public sf::Drawable, public sf::Transformable, public MouseEvents, public States {
private:
    std::vector<SFMLCard> allCards;

    SFMLCardOutline cardOutline;

    CardPile cardPile;

    sf::Vector2f cardHandPosSF;
    sf::Vector2f cardSizeSF;

    sf::FloatRect bounds;

    bool outline = true;

    bool init = false;
//    sf::Transform combinedTransform;

public:
    SFMLCardPile();
    SFMLCardPile(CardPile &cardPile);

    void addCard(const BaseCard& baseCard);
    void setCardPile(CardPile cPile);

    void setOutline(bool val);
    bool getOutline();

    CardPile& getCardPile();
    std::vector<SFMLCard> getSFMLCards();

    sf::FloatRect getBounds();


    void setPosition(float x, float y);
    void setOrigin(sf::Vector2f origin);
    void setRotation(float angle);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
//    void setPosition(float x, float y);
};


#endif //CS3A_KINGS_CORNER_SFMLCARDPILE_H
