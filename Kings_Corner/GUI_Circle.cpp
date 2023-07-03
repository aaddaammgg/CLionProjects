//
// Created by Quantum on 7/2/2023.
//

#include "GUI_Circle.h"

GUI_Circle::GUI_Circle(sf::Color color) {
    circle.setFillColor(color);
    circle.setRadius(50.f);

    setBounds({0,0,100,100});
}

void GUI_Circle::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    window.draw(circle, states);
}

void GUI_Circle::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIAdapter::addEventHandler(window, event);
}

void GUI_Circle::update(sf::RenderTarget& window) {

}
