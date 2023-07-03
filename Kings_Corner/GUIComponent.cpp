//
// Created by Quantum on 5/13/2023.
//

#include "GUIComponent.h"

sf::FloatRect GUIComponent::getBounds() {
    _bounds.left = getPosition().x;
    _bounds.top = getPosition().y;

    return _bounds;
}

void GUIComponent::setBounds(sf::FloatRect bounds) {
    _bounds = bounds;
}