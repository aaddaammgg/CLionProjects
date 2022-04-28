//
// Created by Adam G. on 4/27/22.
//

#include "Slider.h"

Slider::Slider() {
    box.setFillColor(sf::Color::Black);
    dot.setFillColor(sf::Color::Black);
    dot.setRadius(20);
//    dot.setOrigin({0, 0});
    dot.setOrigin({20 / 2, 20 / 2});
}

float Slider::getValue() {
    return value;
}

void Slider::setValue(float val) {
    value = val;

    if (value < 0) {
        value = 0;
    } else if (value > 100) {
        value = 100;
    }

    float max = getSize().x - dot.getRadius();
    float x = max * value / 100;

    dot.setPosition(x, 0);
}

void Slider::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);

    box.setSize(size);
}

void Slider::onMouseMoved(sf::Vector2f pos) {
    if (isEnabled(SELECTED)) {
        sf::Vector2f point = getTransform().getInverse().transformPoint(pos);
        setValue(100 * point.x / getSize().x);
    }
}

void Slider::onMousePressed(sf::Mouse::Button button, sf::Vector2f pos) {
    sf::FloatRect dotBounds = box.getGlobalBounds();
    sf::FloatRect dotPosTransform = getTransform().transformRect(dotBounds);

    if (button == sf::Mouse::Left && !isEnabled(SELECTED) && dotPosTransform.contains(pos)) {
        enableState(SELECTED);
    }
}

void Slider::onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {
    disableState(SELECTED);
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(box, states);
    window.draw(dot, states);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIComponent::addEventHandler(window, event);
}

void Slider::update() {

}
