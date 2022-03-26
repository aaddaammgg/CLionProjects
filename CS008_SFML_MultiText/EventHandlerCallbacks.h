//
// Created by Adam G. on 3/25/2022.
//

#ifndef CS008_SFML_TYPING_EVENTHANDLERCALLBACKS_H
#define CS008_SFML_TYPING_EVENTHANDLERCALLBACKS_H

#include <SFML/Graphics.hpp>

class EventHandlerCallbacks {
private:
    static sf::Vector2f getMousePos(sf::RenderWindow &window);
public:

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    virtual void onMouseMoved(sf::Vector2f pos) {};
    virtual void onMousePressed(sf::Mouse::Button button, sf::Vector2f pos) {};
    virtual void onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {};
    virtual void onMouseWheelMoved(int delta) {};
    virtual void onKeyPressed(const sf::Event::KeyEvent& key) {};
    virtual void onKeyReleased(const sf::Event::KeyEvent& key) {};
    virtual void onTextEntered(sf::Uint32 unicode) {};
};


#endif //CS008_SFML_TYPING_EVENTHANDLERCALLBACKS_H
