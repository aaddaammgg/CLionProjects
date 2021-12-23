//
// https://github.com/limepixl/falling-snow/blob/master/src/main.cpp
// Modified to fit my project

#include "SFMLSnowFalling.h"

SFMLSnowFalling::SFMLSnowFalling() {
    snowFlakes.reserve(snowFlakeCount);
}

void SFMLSnowFalling::createSnowFlake() {
    sf::CircleShape flake(float(rand()) / (float)(RAND_MAX / 3.0f) + 0.5f);
    flake.setPosition(float(rand() % WINDOW_WIDTH), 0.0f);
    flake.setFillColor(sf::Color::White);

    snowFlakes.emplace_back(flake);
}

void SFMLSnowFalling::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto & snowFlake : snowFlakes) {
        window.draw(snowFlake);
    }
}

void SFMLSnowFalling::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SFMLSnowFalling::update(sf::RenderWindow &window) {
    elapsed++;

    for (int i = 0; i < snowFlakes.size(); i++) {
        snowFlakes[i].move(0.0f, snowFlakes[i].getRadius() * 0.4f);

        if (snowFlakes[i].getPosition().y >= WINDOW_HEIGHT) {
            snowFlakes.erase(snowFlakes.begin() + i);
        }
    }

    if (elapsed >= delay && snowFlakes.size() < snowFlakeCount) {
        createSnowFlake();
        elapsed = 0;
    }
}
