//
// Created by NAMEHERE on 12/2/2021.
//

#include "MouseEvents.h"

bool MouseEvents::clicked = false;
bool MouseEvents::isSelected = true;
sf::Vector2f MouseEvents::oldMousePos = {};

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event, sf::FloatRect globalBounds, sf::Vector2f& newPos) {
    _eventHandler(window, event, globalBounds);

    if (_dragging) {
        newPos = currentMousePos;
    }
}

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event, sf::Sprite &sprite) {
    _eventHandler(window, event, sprite.getGlobalBounds());

    if (_dragging) {
        sprite.setPosition(static_cast<float>(currentMousePos.x), static_cast<float>(currentMousePos.y));
    }
}

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event, sf::Shape &shape) {
    _eventHandler(window, event, shape.getGlobalBounds());

    if (_dragging) {
        shape.setPosition(static_cast<float>(currentMousePos.x), static_cast<float>(currentMousePos.y));
    }
}

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event, sf::RectangleShape &shape) {
    _eventHandler(window, event, shape.getGlobalBounds());

    if (_dragging) {
        shape.setPosition(static_cast<float>(currentMousePos.x), static_cast<float>(currentMousePos.y));
    }
}

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event, sf::RoundedRectangleShape &shape) {
    _eventHandler(window, event, shape.getGlobalBounds());

    if (_dragging) {
        shape.setPosition(static_cast<float>(currentMousePos.x), static_cast<float>(currentMousePos.y));
    }
}

void MouseEvents::_eventHandler(sf::RenderWindow &window, sf::Event &event, sf::FloatRect globalBounds) {
    if (!_dragging && !checkDragging) {
        _mouseButtonPressed = false;
        _mouseButtonReleased = false;
        _mouseButtonReleasedDelay = false;
    }

//    std::cout << "width: " << globalBounds.width << " height: " << globalBounds.height << " left: " << globalBounds.left << " top: " << globalBounds.top << std::endl;


    currentMousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    bool containsMouse = globalBounds.contains(currentMousePos);



    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked) {
        clicked = true;
        oldMousePos = currentMousePos;
    }

    if (containsMouse) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !checkDragging && isSelected && !distanceGreaterEqual(21)) {
            _mouseButtonPressed = true;
            checkDragging = true;

            _isSelected = true;
            isSelected = false;
        }

//        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//
//            mouseButtonReleased();
//        }

        if (_changeCursorOnHover && !_hovering) {
            changeMouseCursor(window, sf::Cursor::Hand);
        }

        _hovering = true;
    } else if (!_dragging) {
        if (_changeCursorOnHover && _hovering) {

            changeMouseCursor(window, sf::Cursor::Arrow);
        }

        _hovering = false;
    }

    if (event.type == sf::Event::MouseMoved && _mouseButtonPressed && _isDraggable && _isSelected) {
        if (distanceGreaterEqual(20)) {
            _dragging = true;
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

//    std::cout << "mouse released" << std::endl;

    if (_lastClickedTime + 1 <= time(nullptr)) {
        _lastClickedTime = time(nullptr);
        _mouseButtonReleasedDelay = true;
    }

    _mouseButtonReleased = true;
}

void MouseEvents::changeMouseCursor(sf::RenderWindow& window, sf::Cursor::Type type) {
    sf::Cursor cursor;
    if (cursor.loadFromSystem(type))
        window.setMouseCursor(cursor);
}

float MouseEvents::distancePoints(sf::Vector2f point1, sf::Vector2f point2) {
    return sqrt(pow(point2.x - point1.x, 2) +
                pow(point2.y - point1.y, 2) * 1.0);
}

bool MouseEvents::distanceGreaterEqual(float distance) {
    return distancePoints(currentMousePos, oldMousePos) >= distance;
}

void MouseEvents::setDraggable(bool isDraggable) {
    this->_isDraggable = isDraggable;
}

void MouseEvents::setChangeCursorOnHover(bool changeCursorOnHover) {
    this->_changeCursorOnHover = changeCursorOnHover;
}

bool MouseEvents::isDraggable() const {
    return this->_isDraggable;
}

bool MouseEvents::isDragging() const {
    return this->_dragging;
}

bool MouseEvents::isHovering() const {
    return this->_hovering;
}

bool MouseEvents::mouseButtonPressed() const {
    return this->_mouseButtonPressed;
}

bool MouseEvents::mouseButtonReleased(bool delay) const {
    return (delay) ? this->_mouseButtonReleasedDelay : this->_mouseButtonReleased;
}
