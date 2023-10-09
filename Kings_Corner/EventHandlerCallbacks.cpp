//
// Created by Adam G. on 3/25/2022.
//

#include "EventHandlerCallbacks.h"

sf::Clock EventHandlerCallbacks::clock;
int EventHandlerCallbacks::clicks = 0;
GUIComponent* EventHandlerCallbacks::focusedComponent = nullptr;
bool EventHandlerCallbacks::_mouseButtonPressed = false;

void EventHandlerCallbacks::addEventHandler(sf::RenderWindow &window, sf::Event event, GUIComponent* component) {
    auto* componentMouseEvents = (EventHandlerCallbacks*)component;
    sf::FloatRect bounds = component->getLocalBounds();

    bool isMouseHoveringComponent = bounds.contains(getMousePos(window));

    if (isMouseHoveringComponent) {
        if (_mouseButtonPressed) {
            focusedComponent = component;
        }

        _hovering = true;
    } else if (!isDragging()) {
        _hovering = false;
    } else {
        return;
    }

    switch (event.type) {
        case sf::Event::MouseMoved: {
            if (_mouseButtonPressed && componentMouseEvents->isDraggable() && focusedComponent == component) {
                _dragging = true;

                sf::Vector2f dimensions = {component->getLocalBounds().width / 2, component->getLocalBounds().height / 2};

                component->setPosition(getMousePos(window) - dimensions);
            }

            onMouseMoved(getMousePos(window));
            break;
        }
        case sf::Event::MouseButtonPressed: {
            _mouseButtonPressed = true;
            onMousePressed(event.mouseButton.button, getMousePos(window));
            break;
        }
        case sf::Event::MouseButtonReleased: {
            _mouseButtonPressed = false;
            _dragging = false;
            countClicks();
            onMouseReleased(event.mouseButton.button, getMousePos(window));
            break;
        }
        case sf::Event::MouseWheelScrolled:
            onMouseWheelScrolled(event.mouseWheelScroll.wheel, event.mouseWheelScroll.delta, getMousePos(window));
            break;
        case sf::Event::KeyPressed:
            onKeyPressed(event.key);
            break;
        case sf::Event::KeyReleased:
            onKeyReleased(event.key);
            break;
        case sf::Event::TextEntered:
            onTextEntered(event.text.unicode);
            break;
        default:
            break;
    }
}

void EventHandlerCallbacks::setDraggable(bool isDraggable) {
    _isDraggable = isDraggable;
}

bool EventHandlerCallbacks::isHovering() const {
    return false;
}

bool EventHandlerCallbacks::isDraggable() const {
    return _isDraggable;
}

bool EventHandlerCallbacks::isDragging() const {
    return _dragging;
}

void EventHandlerCallbacks::countClicks() {
    clicks++;

    if (clock.getElapsedTime() >= sf::milliseconds(500)) {
        clock.restart();
        clicks = 1;
    }
}

bool EventHandlerCallbacks::didMouseDoubleClick() {
    return clicks == 2;
}

bool EventHandlerCallbacks::didMouseTripleClick() {
    return clicks == 3;
}

sf::Vector2f EventHandlerCallbacks::getMousePos(sf::RenderWindow &window) {
    return window.mapPixelToCoords(sf::Mouse::getPosition(window));
}