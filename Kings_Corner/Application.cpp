//
// Created by Quantum on 5/14/2023.
//

#include "Application.h"

void Application::run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({500, 500, 32}, "Kings Corner", sf::Style::Close, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(50.f);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color(sf::Color::Black));
        window.draw(circle);
        window.display();
    }
}
