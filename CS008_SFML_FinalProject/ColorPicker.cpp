//
// Created by Adam G. on 5/3/22.
//

#include "ColorPicker.h"

ColorPicker::ColorPicker() {
    int i = 0;
    for (auto & box : colors) {
        box.setSize({boxSize, boxSize});
        box.setPosition({static_cast<float>(i * boxSize), 0});
        box.setFillColor(getColor(static_cast<COLOR>(i)));
        box.setOutlineThickness(1);
        box.setOutlineColor(sf::Color::White);
        i++;
    }
}

sf::Color ColorPicker::getColor(ColorPicker::COLOR c) {
    switch (c) {
        case RED:
            return sf::Color::Red;
        case GREEN:
            return sf::Color::Green;
        case BLUE:
            return sf::Color::Blue;
        case CYAN:
            return sf::Color::Cyan;
        case YELLOW:
            return sf::Color::Yellow;
        case ORANGE:
            return {255, 165, 0};
        case BROWN:
            return {139,69,19};
        case PURPLE:
            return {128,0,128};
        case PINK:
            return {255,105,180};
        case WHITE:
            return sf::Color::White;
        case BLACK:
            return sf::Color::Black;
        default:
            return {0, 0, 0};
    }
}

sf::Color ColorPicker::getColor() {
    return getColor(selected);
}

void ColorPicker::setCallBack(std::function<void(const sf::Color &)> cb) {
    callBack = std::move(cb);
}

void ColorPicker::setLabel(const std::string &str) {
    label = str;
    setPosition(getPosition());
}

void ColorPicker::setLabelSize(unsigned int s) {
    label.setCharacterSize(s);
    setPosition(getPosition());
}

void ColorPicker::updateSize() {
    float width = colors[LAST_COLORS - 1].getPosition().x + colors[LAST_COLORS - 1].getSize().x;
    float height = boxSize + label.getCharacterSize();
    setSize({width, height});
}

void ColorPicker::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);
}

void ColorPicker::setPosition(sf::Vector2f pos) {
    GUIComponent::setPosition(pos);

    int i = 0;
    for (auto & box : colors) {
        box.setPosition({static_cast<float>(i * boxSize), static_cast<float>(label.getCharacterSize() + 10)});
        i++;
    }

    updateSize();
}

void ColorPicker::onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {
    int i = 0;
    for (auto & box : colors) {
        sf::FloatRect boxBounds = box.getGlobalBounds();
        sf::FloatRect boxPosTransform = getTransform().transformRect(boxBounds);

        if (boxPosTransform.contains(pos)) {
            selected = static_cast<COLOR>(i);
            callBack(getColor(selected));
        }

        i++;
    }
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIComponentAdapter::addEventHandler(window, event);
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(label, states);
    for (auto & box : colors) {
        window.draw(box, states);
    }
}

void ColorPicker::update() {
    GUIComponentAdapter::update();
}
