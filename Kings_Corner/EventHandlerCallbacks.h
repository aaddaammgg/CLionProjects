//
// Created by Adam G. on 3/25/2022.
//

#ifndef CS008_SFML_TYPING_EVENTHANDLERCALLBACKS_H
#define CS008_SFML_TYPING_EVENTHANDLERCALLBACKS_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include <iostream>

class EventHandlerCallbacks {
private:
    static sf::Vector2f getMousePos(sf::RenderWindow &window);
    static sf::Clock clock;
    static int clicks;
    static void countClicks();
    static bool _mouseButtonPressed;

    bool _isDraggable = false;
    bool _hovering = false;
    bool _dragging = false;
public:
    static GUIComponent* focusedComponent;

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event, GUIComponent* component);

    static bool didMouseDoubleClick();
    static bool didMouseTripleClick();

    void setDraggable(bool isDraggable);
    bool isHovering() const;
    bool isDraggable() const;

    virtual void onMouseMoved(sf::Vector2f pos) {};
    virtual void onMousePressed(sf::Mouse::Button button, sf::Vector2f pos) {};
    virtual void onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {};
    virtual void onMouseWheelScrolled(sf::Mouse::Wheel wheel, float delta, sf::Vector2f pos) {};
    virtual void onKeyPressed(const sf::Event::KeyEvent& key) {};
    virtual void onKeyReleased(const sf::Event::KeyEvent& key) {};
    virtual void onTextEntered(sf::Uint32 unicode) {};

    bool isDragging() const;
};


#endif //CS008_SFML_TYPING_EVENTHANDLERCALLBACKS_H
