//
// Created by Adam G. on 4/27/22.
//

#include "Slider.h"

Slider::Slider() {
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2);

    dot.setFillColor(sf::Color::Transparent);
    dot.setOutlineColor(sf::Color::Black);
    dot.setOutlineThickness(2);
    dot.setRadius(20);
//    dot.setOrigin({0, 0});
    dot.setOrigin({20 / 2, 20 / 2});

    disableState(HIDDEN);
    disableState(DISABLED);
    disableState(SELECTED);
    disableState(CLICKED);
}

float Slider::getValue() const {
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
    if (!isEnabled(CLICKED)) {
        return;
    }

    sf::Vector2f point = getTransform().getInverse().transformPoint(pos);
    setValue(100 * point.x / getSize().x);
}

void Slider::onMousePressed(sf::Mouse::Button button, sf::Vector2f pos) {
    sf::FloatRect dotBounds = dot.getGlobalBounds();
    sf::FloatRect dotPosTransform = getTransform().transformRect(dotBounds);

    sf::FloatRect boxBounds = box.getGlobalBounds();
    sf::FloatRect boxPosTransform = getTransform().transformRect(boxBounds);

    if (button == sf::Mouse::Left && !isEnabled(CLICKED) && (dotPosTransform.contains(pos) || boxPosTransform.contains(pos))) {
        enableState(CLICKED);
        enableState(SELECTED);
    }
}

void Slider::onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {
    sf::FloatRect boxBounds = box.getGlobalBounds();
    sf::FloatRect boxPosTransform = getTransform().transformRect(boxBounds);

    if (!boxPosTransform.contains(pos) && !isEnabled(CLICKED)) {
        disableState(SELECTED);
    }

    disableState(CLICKED);
}

void Slider::onKeyPressed(const sf::Event::KeyEvent &key) {
    if (!isEnabled(SELECTED)) {
        return;
    }

    switch (key.code) {
        case sf::Keyboard::Left:
            setValue(value - 10);
            break;
        case sf::Keyboard::Right:
            setValue(value + 10);
            break;
        default:
            break;
    }
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (isEnabled(HIDDEN)) {
        return;
    }
    states.transform *= getTransform();
    window.draw(box, states);
    window.draw(dot, states);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (isEnabled(HIDDEN) || isEnabled(DISABLED)) {
        return;
    }
    GUIComponent::addEventHandler(window, event);
}

void Slider::update() {

}
