//
// Created by Adam G. on 5/2/22.
//

#ifndef CS008_SFML_FINALPROJECT_LOGOMAKER_H
#define CS008_SFML_FINALPROJECT_LOGOMAKER_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "MenuBar.h"
#include "DisplayLogo.h"
#include "TextInput.h"
#include "Slider.h"
#include "ColorPicker.h"
#include "DropdownMenu.h"

class LogoMaker {
private:
    unsigned int WIDTH = 1280 * .8;
    unsigned int HEIGHT = 800 * .8;
    std::string winTitle = "Logo Maker 3000 (ALPHA)";

    sf::RenderWindow renderWindow;
    std::vector<GUIComponent*> components;

    sf::RenderTexture texture;
    sf::Sprite sprite;

    MenuBar menuBar;
    DisplayLogo displayLogo;
    TextInput logoText;

    Slider textOpacity;
    Slider textXAxis;
    Slider textYAxis;
    Slider textFontSize;

    Slider shadowOpacity;
    Slider shadowXAxis;
    Slider shadowYAxis;
    Slider shadowSkew;

    ColorPicker backgroundColor;
    ColorPicker textColor;

    DropdownMenu fontDropdown;

    void updateMinMax();
    void updateLogo();

    void draw();
public:
    void run();
};


#endif //CS008_SFML_FINALPROJECT_LOGOMAKER_H
