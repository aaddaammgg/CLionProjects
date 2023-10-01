//
// Created by Quantum on 5/14/2023.
//

#ifndef KINGS_CORNER_MOUSEEVENTS_H
#define KINGS_CORNER_MOUSEEVENTS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "GUIComponent.h"
#include "GUIAdapter.h"

#define DRAG_DISTANCE 7

class MouseEvents {
private:
    static bool _dragging;
    static bool _hovering;
    static bool _mouseButtonPressed;
    static bool _mouseButtonReleased;
    static bool _mouseButtonReleasedDelay;
    static bool checkIfDragging;

    static bool clicked;
    static bool checkIfSelected;
    static sf::Vector2f oldMousePos;

    static sf::Vector2f currentMousePos;
    static time_t _lastClickedTime;

    static void mouseButtonReleased();
    static double distancePoints(sf::Vector2f point1, sf::Vector2f point2);
    static bool distanceGreaterEqual(double distance);
    static void changeMouseCursor(sf::RenderWindow& window, sf::Cursor::Type type);

    static bool isSelected();

    static void eventHandler(sf::RenderWindow& window, sf::Event& event, GUIComponent* component);
public:
    static GUIComponent* selected;
    static GUIComponent* lastSelected;
    static bool isDragging();
    static bool mouseButtonPressed();
    static bool mouseButtonReleased(bool delay);
    static void eventHandler(sf::RenderWindow& window, sf::Event& event);
};


#endif //KINGS_CORNER_MOUSEEVENTS_H
