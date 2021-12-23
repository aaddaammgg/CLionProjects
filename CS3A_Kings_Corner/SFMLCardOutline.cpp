//
// Created by Adam G. on 12/6/2021.
//

#include "SFMLCardOutline.h"

SFMLCardOutline::SFMLCardOutline() {
    bounds.width = 60;
    bounds.height = 95;

    outlinedCard.setSize({bounds.width, bounds.height});

    outlinedCard.setFillColor(sf::Color(0,0,0,150));
    outlinedCard.setCornersRadius(7);
    outlinedCard.setCornerPointCount(9);

    outlinedCard.setOutlineColor(sf::Color(0,0,0,100));
    outlinedCard.setOutlineThickness(5);
}

sf::FloatRect SFMLCardOutline::getBounds() {
    return bounds;
}

void SFMLCardOutline::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    window.draw(outlinedCard, states);
}
