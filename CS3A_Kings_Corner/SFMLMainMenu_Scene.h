//
// Created by NAMEHERE on 11/24/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLMAINMENU_H
#define CS3A_KINGS_CORNER_SFMLMAINMENU_H

#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "SFMLButton.h"
#include "ScenesENUM.h"
#include "SFMLSpinningKings.h"

class SFMLMainMenu_Scene : public sf::Drawable, public States {
private:
    sf::Text title;
    sf::Text subTitle;
    sf::Text credits;

    sf::Sprite crown;

    SFMLButton playButton;
    SFMLButton quitButton;

    SFMLSpinningKings spinningKings;
public:
    SFMLMainMenu_Scene();

    void eventHandler(sf::RenderWindow& window, sf::Event event, ScenesENUM &scene);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //CS3A_KINGS_CORNER_SFMLMAINMENU_H
