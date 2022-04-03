//
// Created by Adam G. on 3/26/2022.
//

#include "KBShortcuts.h"

bool KBShortcuts::isControl() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
}

bool KBShortcuts::isUndo() {
    return isControl() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

bool KBShortcuts::isRedo() {
    return isControl() && sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
}
