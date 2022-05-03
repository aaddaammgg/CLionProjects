//
// Created by Adam G. on 5/2/22.
//

#ifndef CS008_SFML_FINALPROJECT_LOGOMAKER_H
#define CS008_SFML_FINALPROJECT_LOGOMAKER_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "MenuItem.h"
#include "MenuBar.h"
#include "TextInput.h"

class LogoMaker {
private:
    sf::RenderWindow renderWindow;
    MenuBar menuBar;
    TextInput logoText;

    void draw(std::vector<GUIComponent*>& components, sf::RenderWindow& window);
public:
    void run();
};


#endif //CS008_SFML_FINALPROJECT_LOGOMAKER_H
