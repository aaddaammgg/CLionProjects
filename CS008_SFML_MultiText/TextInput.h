//
// Created by Adam G. on 3/21/22.
//

#ifndef CS008_SFML_TYPING_TEXTINPUT_H
#define CS008_SFML_TYPING_TEXTINPUT_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Typing.h"
#include "CursorBlink.h"

class TextInput : public GUIComponent {
private:
    sf::RectangleShape box;
    CursorBlink cursorBlink;
    Typing typing;
public:
    TextInput();

    void setSize(sf::Vector2f size);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //CS008_SFML_TYPING_TEXTINPUT_H
