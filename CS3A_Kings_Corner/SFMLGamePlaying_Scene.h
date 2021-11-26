//
// Created by Adam Gonzalez on 11/25/21.
//

#ifndef SFML_KINGS_CORNER_SFMLGAMEPLAYING_SCENE_H
#define SFML_KINGS_CORNER_SFMLGAMEPLAYING_SCENE_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "ResourceHolder.h"
#include "ScenesENUM.h"
#include "SFMLButton.h"

#include "SFMLCardHand.h"
#include "Deck.h"
#include "PokerScore.h"
#include "CardHandScorer.h"

class SFMLGamePlaying_Scene : public sf::Drawable {
private:
    sf::Text title;
    SFMLButton exitButton;
    SFMLButton refreshButton;

    CardHand chTest;
    SFMLCardHand sfmlCardHand;
    Deck deck;
public:
    SFMLGamePlaying_Scene();

    void eventHandler(sf::RenderWindow& window, sf::Event event, ScenesENUM &scene);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //SFML_KINGS_CORNER_SFMLGAMEPLAYING_SCENE_H
