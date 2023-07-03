//
// Created by Quantum on 5/14/2023.
//

#ifndef KINGS_CORNER_MOUSEEVENTS_H
#define KINGS_CORNER_MOUSEEVENTS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "GUIComponent.h"

class MouseEvents {
private:
    static GUIComponent* selected;

    bool _changeCursorOnHover = true;
    bool _isDraggable = false;
    static bool _dragging;
    static bool _hovering;
    static bool _mouseButtonPressed;
    static bool _mouseButtonReleased;
    static bool _mouseButtonReleasedDelay;
    static bool checkDragging;

    static bool _isSelected;
    static bool clicked;
    static bool isSelected;
    static sf::Vector2f oldMousePos;

    static sf::Vector2f currentMousePos;
    static time_t _lastClickedTime;

    static void mouseButtonReleased();
    static double distancePoints(sf::Vector2f point1, sf::Vector2f point2);
    static bool distanceGreaterEqual(double distance);
    static void changeMouseCursor(sf::RenderWindow& window, sf::Cursor::Type type);
public:
    void setDraggable(bool isDraggable);
    void setChangeCursorOnHover(bool changeCursorOnHover);

    bool isChangeCursorOnHover();
    bool isHovering();
    bool isDraggable();
    static bool isDragging();
    static bool mouseButtonPressed();
    static bool mouseButtonReleased(bool delay);
protected:
    static void eventHandler(sf::RenderWindow& window, sf::Event& event, GUIComponent* component);
};


#endif //KINGS_CORNER_MOUSEEVENTS_H
