//
// Created by Adam G. on 3/21/22.
//

#include "GUIComponent.h"

GUIComponent::GUIComponent() {
    setSize({10, 10});
}

sf::Vector2f GUIComponent::getSize() {
    return size;
}

void GUIComponent::setSize(sf::Vector2f size) {
    this->size = size;
}
