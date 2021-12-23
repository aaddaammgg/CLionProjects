//
// Created by NAMEHERE on 11/25/21.
//

#ifndef SFML_KINGS_CORNER_SFMLSCENESWITCHER_H
#define SFML_KINGS_CORNER_SFMLSCENESWITCHER_H

#include <SFML/Graphics.hpp>
#include "SceneSwitcher.h"
#include "SFMLMainMenu_Scene.h"
#include "SFMLGamePlaying_Scene.h"
#include "SFMLSnowFalling.h"

class SFMLSceneSwitcher : public sf::Drawable, public SceneSwitcher {
private:
    SFMLSnowFalling snowFalling;
    SFMLMainMenu_Scene mainMenuScene;
    SFMLGamePlaying_Scene gamePlayingScene;
public:
    SFMLSceneSwitcher();
    SFMLSceneSwitcher(ScenesENUM scene);

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update(sf::RenderWindow& window);
};


#endif //SFML_KINGS_CORNER_SFMLSCENESWITCHER_H
