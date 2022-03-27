//
// Created by Adam G. on 3/26/2022.
//

#include "KBShortcuts.h"

bool KBShortcuts::isUndo() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

bool KBShortcuts::isRedo() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
}
