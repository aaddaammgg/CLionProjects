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
    typing.setSize({200, 30});
    typing.setScale({1.5, 1.5});

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            typing.addEventHandler(window, event);
        }
        typing.update();
        window.clear(sf::Color(sf::Color::White));
        window.draw(typing);
        window.display();
    }

    return 0;
}
