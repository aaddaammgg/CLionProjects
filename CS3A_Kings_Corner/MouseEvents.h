//
// Created by NAMEHERE on 12/2/2021.
//

#ifndef CS3A_KINGS_CORNER_MOUSEEVENTS_H
#define CS3A_KINGS_CORNER_MOUSEEVENTS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "RoundedRectangleShape.h"

class MouseEvents {
private:
    bool _changeCursorOnHover = true;
    bool _isDraggable = false;
    bool _dragging = false;
    bool _hovering = false;
    bool _mouseButtonPressed = false;
    bool _mouseButtonReleased = false;
    bool _mouseButtonReleasedDelay = false;
    bool checkDragging = false;

    sf::Vector2f currentMousePos;

    time_t _lastClickedTime = 0;
    void mouseButtonReleased();
    void _eventHandler(sf::RenderWindow& window, sf::Event& event, sf::FloatRect globalBounds);
    float distancePoints(sf::Vector2f point1, sf::Vector2f point2);
    bool distanceGreaterEqual(float distance);
    static void changeMouseCursor(sf::RenderWindow& window, sf::Cursor::Type type);
public:
    void eventHandler(sf::RenderWindow& window, sf::Event& event, sf::FloatRect globalBounds, sf::Vector2f& newPos);
    void eventHandler(sf::RenderWindow& window, sf::Event& event, sf::Sprite& sprite);
    void eventHandler(sf::RenderWindow& window, sf::Event& event, sf::Shape& shape);
    void eventHandler(sf::RenderWindow& window, sf::Event& event, sf::RectangleShape& shape);
    void eventHandler(sf::RenderWindow& window, sf::Event& event, sf::RoundedRectangleShape& shape);

    void setDraggable(bool isDraggable);
    void setChangeCursorOnHover(bool changeCursorOnHover);

    bool isDraggable() const;
    bool isDragging() const;
    bool isHovering() const;
    bool mouseButtonPressed() const;
    bool mouseButtonReleased(bool delay) const;

protected:
    bool _isSelected = false;
    static bool clicked;
    static bool isSelected;
    static sf::Vector2f oldMousePos;

};


#endif //CS3A_KINGS_CORNER_MOUSEEVENTS_H
