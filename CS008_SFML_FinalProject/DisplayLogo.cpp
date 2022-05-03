//
// Created by Adam G. on 5/2/2022.
//

#include "DisplayLogo.h"

DisplayLogo::DisplayLogo() {
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);
    box.setPosition({3,0});
}

MultiText &DisplayLogo::getLogo() {
    return logo;
}

void DisplayLogo::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);

    size.x -= 6;
    box.setSize(size);
}

void DisplayLogo::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(box, states);
    window.draw(logo, states);
}

void DisplayLogo::update() {

}
