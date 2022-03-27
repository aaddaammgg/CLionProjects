//
// Created by Adam G. on 3/21/2022.
//

#include "CursorBlink.h"

CursorBlink::CursorBlink() {
    line.setFillColor(sf::Color::Black);
    line.setSize({2,8});
    enableState(HIDDEN);
}

int CursorBlink::getIndex() const {
    return index;
}

void CursorBlink::setIndex(int index) {
    this->index = index;
}

void CursorBlink::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);
    line.setSize(size);
}

Snapshot &CursorBlink::getSnapshot() {

}

void CursorBlink::applySnapshot(const Snapshot &snapshot) {

}

void CursorBlink::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!isEnabled(HIDDEN) && isEnabled(SELECTED)) {
        states.transform *= getTransform();
        window.draw(line, states);
    }
}

void CursorBlink::update() {
    if (blinkFrequency.getElapsedTime() >= sf::milliseconds(400) && isEnabled(SELECTED)) {
        blinkFrequency.restart();
        if (isEnabled(HIDDEN)) {
            disableState(HIDDEN);
        } else {
            enableState(HIDDEN);
        }

    }
}
