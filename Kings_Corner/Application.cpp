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

    std::vector<GUIAdapter*> components;

    GUI_Circle circle(sf::Color::Green);

    circle.setDraggable(true);
    circle.setPosition(0, 0);

    GUI_Circle circle2(sf::Color::Red);
    circle2.setDraggable(true);
    circle2.setPosition(125, 0);

    components.push_back(&circle);
    components.push_back(&circle2);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            for (auto* component : components) {
                component->addEventHandler(window, event);
            }
        }

        for (auto* component : components) {
            component->update(window);
        }

        window.clear(sf::Color(sf::Color::Black));
        for (auto* component : components) {
            window.draw(*component);
        }
        window.display();
    }
}
