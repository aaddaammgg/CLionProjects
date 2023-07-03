//
// Created by Quantum on 7/2/2023.
//

#include "GUIAdapter.h"

void GUIAdapter::draw(sf::RenderTarget& window, sf::RenderStates states) const {

}

void GUIAdapter::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    MouseEvents::eventHandler(window, event, (GUIComponent*)this);
}

void GUIAdapter::update(sf::RenderTarget& window) {

}