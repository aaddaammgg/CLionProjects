//
// Created by Quantum on 5/14/2023.
//

#include "MouseEvents.h"

GUIComponent* MouseEvents::selected;

//bool MouseEvents::_changeCursorOnHover = true;
//bool MouseEvents::_isDraggable = false;
bool MouseEvents::_dragging = false;
bool MouseEvents::_hovering = false;
bool MouseEvents::_mouseButtonPressed = false;
bool MouseEvents::_mouseButtonReleased = false;
bool MouseEvents::_mouseButtonReleasedDelay = false;
bool MouseEvents::checkDragging = false;

bool MouseEvents::_isSelected = false;
bool MouseEvents::clicked = false;
bool MouseEvents::isSelected = true;
sf::Vector2f MouseEvents::oldMousePos;

sf::Vector2f MouseEvents::currentMousePos;
time_t MouseEvents::_lastClickedTime = 0;

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event, GUIComponent* component) {
    auto* componentMouseEvents = (MouseEvents*)component;

    if (!_dragging && !checkDragging) {
        _mouseButtonPressed = false;
        _mouseButtonReleased = false;
        _mouseButtonReleasedDelay = false;
    }

    currentMousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    sf::FloatRect bounds = component->getBounds();

    bool containsMouse = bounds.contains(currentMousePos);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked) {
        clicked = true;
        oldMousePos = currentMousePos;
    }

    if (containsMouse) {
        if (clicked && !checkDragging && isSelected && !distanceGreaterEqual(21)) {
            _mouseButtonPressed = true;
            checkDragging = true;

            _isSelected = true;
            isSelected = false;

            selected = component;
        }

        if (componentMouseEvents->isChangeCursorOnHover() && !_hovering) {
            changeMouseCursor(window, sf::Cursor::Hand);
        }

        _hovering = true;
    } else if (!_dragging) {
        if (componentMouseEvents->isChangeCursorOnHover() && _hovering) {

            changeMouseCursor(window, sf::Cursor::Arrow);
        }

        _hovering = false;
    }

    if (event.type == sf::Event::MouseMoved && _mouseButtonPressed && componentMouseEvents->isDraggable() && _isSelected) {
        if (distanceGreaterEqual(20) && selected == component) {
            _dragging = true;

            sf::Vector2f dimensions = {component->getBounds().width / 2, component->getBounds().height / 2};

            component->setPosition(currentMousePos - dimensions);
        }
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        mouseButtonReleased();
    } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right) {
        mouseButtonReleased();
    }
}

void MouseEvents::mouseButtonReleased() {
    checkDragging = false;
    clicked = false;

    if (!_isSelected) return;


    _isSelected = false;
    isSelected = true;

    if (distanceGreaterEqual(20) && !_dragging) return;

    _dragging = false;

    if (_lastClickedTime + 1 <= time(nullptr)) {
        _lastClickedTime = time(nullptr);
        _mouseButtonReleasedDelay = true;
    }

    selected = nullptr;
    _mouseButtonReleased = true;
}

void MouseEvents::changeMouseCursor(sf::RenderWindow& window, sf::Cursor::Type type) {
//    sf::Cursor cursor;
//    if (cursor.loadFromSystem(type))
//        window.setMouseCursor(cursor);
    std::cout << type << std::endl;
}

double MouseEvents::distancePoints(sf::Vector2f point1, sf::Vector2f point2) {
    return sqrt(pow(point2.x - point1.x, 2) +
                pow(point2.y - point1.y, 2) * 1.0);
}

bool MouseEvents::distanceGreaterEqual(double distance) {
    return distancePoints(currentMousePos, oldMousePos) >= distance;
}

void MouseEvents::setDraggable(bool isDraggable) {
    _isDraggable = isDraggable;
}

void MouseEvents::setChangeCursorOnHover(bool changeCursorOnHover) {
    _changeCursorOnHover = changeCursorOnHover;
}

bool MouseEvents::isChangeCursorOnHover() {
    return _changeCursorOnHover;
}

bool MouseEvents::isHovering() {
    return _hovering;
}

bool MouseEvents::isDraggable() {
    return _isDraggable;
}

bool MouseEvents::isDragging() {
    return _dragging;
}

bool MouseEvents::mouseButtonPressed() {
    return _mouseButtonPressed;
}

bool MouseEvents::mouseButtonReleased(bool delay) {
    return (delay) ? _mouseButtonReleasedDelay : _mouseButtonReleased;
}