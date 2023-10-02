//
// Created by Quantum on 5/14/2023.
//

#include "MouseEvents.h"

GUIComponent* MouseEvents::selected = nullptr;
GUIComponent* MouseEvents::lastSelected = nullptr;
GUIComponent* MouseEvents::hovered = nullptr;

bool MouseEvents::_dragging = false;
bool MouseEvents::_hovering = false;
bool MouseEvents::_mouseButtonPressed = false;
bool MouseEvents::_mouseButtonReleased = false;
bool MouseEvents::_mouseButtonReleasedDelay = false;
bool MouseEvents::checkIfDragging = false;

bool MouseEvents::clicked = false;
bool MouseEvents::checkIfSelected = true;
sf::Vector2f MouseEvents::oldMousePos;

sf::Vector2f MouseEvents::currentMousePos;
time_t MouseEvents::_lastClickedTime = 0;

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event) {
    if (selected == nullptr) {
        for (auto component : GUIAdapter::components) {
            eventHandler(window, event, component);
        }
    } else {
        eventHandler(window, event, selected);
    }
}

void MouseEvents::eventHandler(sf::RenderWindow &window, sf::Event &event, GUIComponent* component) {
//    auto* componentMouseEvents = (MouseEvents*)component;

    if (component->isEnabled(DISABLED)) {
        return;
    }

    if (!isDragging() && !checkIfDragging) {
        _mouseButtonPressed = false;
        _mouseButtonReleased = false;
        _mouseButtonReleasedDelay = false;
    }

    currentMousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    sf::FloatRect bounds = component->getBounds();

    bool isMouseHoveringComponent = bounds.contains(currentMousePos);

    if (isMouseHoveringComponent) {
        hovered = component;
    }

    // This is for checking the distance between the oldMousePos and currentMousePos
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked) {
        clicked = true;
        oldMousePos = currentMousePos;
    }

    if (isMouseHoveringComponent) {
        if (clicked && !checkIfDragging && checkIfSelected && !distanceGreaterEqual(DRAG_DISTANCE + 1)) {
            _mouseButtonPressed = true;
            checkIfDragging = true;

            checkIfSelected = false;

            // Move component to end to draw on top of everything else
            GUIAdapter::components.insert(GUIAdapter::components.end(), component);

            selected = component;
            lastSelected = component;
        }

//        if (component->isEnabled(CHANGE_CURSOR) && !_hovering) {
//            changeMouseCursor(window, sf::Cursor::Hand);
//        }

        component->enableState(HOVERED);

        _hovering = true;
    } else if (!isDragging()) {
        if (component->isEnabled(CHANGE_CURSOR) && _hovering) {

            changeMouseCursor(window, sf::Cursor::Arrow);
        }

        component->disableState(HOVERED);

        _hovering = false;
    }

    if (event.type == sf::Event::MouseMoved && _mouseButtonPressed && component->isEnabled(IS_DRAGGABLE) && isSelected()) {
        if (selected == component && (distanceGreaterEqual(DRAG_DISTANCE) || _dragging)) {
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
    checkIfDragging = false;
    clicked = false;

    if (!isSelected()) return;

    checkIfSelected = true;

    if (distanceGreaterEqual(DRAG_DISTANCE) && !isDragging()) return;

    _dragging = false;

    if (_lastClickedTime + 1 <= time(nullptr)) {
        _lastClickedTime = time(nullptr);
        _mouseButtonReleasedDelay = true;
    }

    _mouseButtonReleased = true;
    selected = nullptr;
}

bool MouseEvents::isSelected() {
    return selected != nullptr;
}

void MouseEvents::changeMouseCursor(sf::RenderWindow& window, sf::Cursor::Type type) {
//    sf::Cursor cursor;
//    if (cursor.loadFromSystem(type))
//        window.setMouseCursor(cursor);
//    std::cout << type << std::endl;
}

double MouseEvents::distancePoints(sf::Vector2f point1, sf::Vector2f point2) {
    return sqrt(pow(point2.x - point1.x, 2) +
                pow(point2.y - point1.y, 2) * 1.0);
}

bool MouseEvents::distanceGreaterEqual(double distance) {
    return distancePoints(currentMousePos, oldMousePos) >= distance;
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