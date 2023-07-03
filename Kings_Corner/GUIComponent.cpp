//
// Created by Quantum on 5/13/2023.
//

#include "GUIComponent.h"

sf::FloatRect GUIComponent::getBounds() {
    return _bounds;
}

void GUIComponent::setBounds(sf::FloatRect bounds) {
    _bounds = bounds;
}