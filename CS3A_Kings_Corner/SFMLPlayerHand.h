//
// Created by Adam G. on 12/7/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLPLAYERHAND_H
#define CS3A_KINGS_CORNER_SFMLPLAYERHAND_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "BasePlayer.h"
#include "SFMLCard.h"
#include "SFMLCardPile.h"

class SFMLPlayerHand : public sf::Drawable, public sf::Transformable {
private:
    std::vector<SFMLCard> allCards;
    BasePlayer player;
    bool hidden = false;
    sf::FloatRect bounds;
    sf::RectangleShape bg;
    void fixCardPositions();
public:
    SFMLPlayerHand();

    void addCard(const BaseCard& baseCard);
    void setCardPile(CardPile cPile);
    void setHidden(bool val);

    CardPile& getCardPile();
    std::vector<SFMLCard> getSFMLCards();
    BasePlayer& getPlayer();
    bool isHidden() const;

    sf::FloatRect getBounds();

    void setPosition(float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};


#endif //CS3A_KINGS_CORNER_SFMLPLAYERHAND_H
