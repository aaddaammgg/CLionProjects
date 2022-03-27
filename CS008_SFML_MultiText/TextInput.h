//
// Created by Adam G. on 3/21/22.
//

#ifndef CS008_SFML_TYPING_TEXTINPUT_H
#define CS008_SFML_TYPING_TEXTINPUT_H

#include <SFML/Graphics.hpp>
#include "GUIComponentAdapter.h"
#include "Typing.h"
#include "CursorBlink.h"

class TextInput : public GUIComponentAdapter {
private:
    sf::RectangleShape box;
    CursorBlink cursorBlink;
    Typing typing;
public:
    TextInput();

    void setSize(sf::Vector2f size);

    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    virtual void onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos);
    virtual void onKeyPressed(const sf::Event::KeyEvent& key);
    virtual void onTextEntered(sf::Uint32 unicode);

    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //CS008_SFML_TYPING_TEXTINPUT_H
