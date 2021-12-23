//
// Created by NAMEHERE on 11/25/21.
//

#ifndef SFML_KINGS_CORNER_SFMLGAMEPLAYING_SCENE_H
#define SFML_KINGS_CORNER_SFMLGAMEPLAYING_SCENE_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "ResourceHolder.h"
#include "ScenesENUM.h"
#include "SFMLButton.h"

#include "SFMLCardPile.h"
#include "Deck.h"
#include "SFMLCompass.h"
#include "SFMLGameTurnOrder.h"

class SFMLGamePlaying_Scene : public sf::Drawable {
private:
    sf::Text title;

    SFMLButton exitButton;
    SFMLButton newGameButton;

    SFMLCompass compass;
//    SFMLGameTurnOrder turnOrder;


//    CardPile cpTest;
//    SFMLCardPile sfmlCardPile;
//    Deck deck;
public:
    SFMLGamePlaying_Scene();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event, ScenesENUM &scene);
    void update(sf::RenderWindow& window);
};


#endif //SFML_KINGS_CORNER_SFMLGAMEPLAYING_SCENE_H
