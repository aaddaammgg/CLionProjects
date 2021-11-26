//
// Created by Adam G. on 10/31/2021.
//

#ifndef CS3A_POKER_ANALYSIS_SFMLCARDHAND_H
#define CS3A_POKER_ANALYSIS_SFMLCARDHAND_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SFMLCard.h"
#include "CardHand.h"

class SFMLCardHand : public sf::Drawable {
private:
    std::vector<SFMLCard> allCards;

    CardHand cardHand;

    sf::Vector2f cardHandPosSF;
    sf::Vector2f cardSizeSF;
public:
    SFMLCardHand();
    SFMLCardHand(CardHand &cardHand);

    void addCard(SFMLCard card);

    CardHand getCardHand();
    std::vector<SFMLCard> getSFMLCards();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
};


#endif //CS3A_POKER_ANALYSIS_SFMLCARDHAND_H
