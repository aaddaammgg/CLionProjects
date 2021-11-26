//
// Created by Adam G. on 11/24/2021.
//

#ifndef CS3A_KINGS_CORNER_SFMLMAINMENU_H
#define CS3A_KINGS_CORNER_SFMLMAINMENU_H

#include <SFML/Graphics.hpp>
#include "SFMLButton.h"
#include "DEFINITIONS.h"

class SFMLMainMenu : public sf::Drawable, public States {
private:
    sf::Text title;
    sf::Text subTitle;

    SFMLButton playButton;
    SFMLButton quitButton;
public:
    SFMLMainMenu();

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //CS3A_KINGS_CORNER_SFMLMAINMENU_H
