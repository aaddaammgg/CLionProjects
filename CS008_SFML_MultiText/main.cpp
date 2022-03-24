#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextInput.h"

int main() {
    srand(time(nullptr));
    sf::err().rdbuf(nullptr);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({500, 500, 32}, "SFML Typing", sf::Style::Close, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

    TextInput typing;

    typing.setPosition(100,50);
    typing.setSize({200, 50});
//    typing.setScale({1.5, 1.5});

    std::vector<GUIComponent*> components;
    components.push_back(&typing);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            for (auto & component : components) {
                component->addEventHandler(window, event);
            }
        }
        for (auto & component : components) {
            component->update();
        }
        window.clear(sf::Color(sf::Color::White));
        for (auto & component : components) {
            window.draw(*component);
        }
        window.display();
    }

    return 0;
}
