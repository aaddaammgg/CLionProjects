//
// Created by Quantum on 5/13/2023.
//

#include "GUIComponent.h"

sf::FloatRect GUIComponent::getLocalBounds() const {
    return {getPosition().x, getPosition().y, _bounds.width, _bounds.height};
}

sf::FloatRect GUIComponent::getGlobalBounds() const {
    return getTransform().transformRect(getLocalBounds());
}

void GUIComponent::setBounds(sf::FloatRect bounds) {
    _bounds = bounds;
}