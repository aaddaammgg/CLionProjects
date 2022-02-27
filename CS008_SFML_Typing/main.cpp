#include <iostream>
#include <SFML/Graphics.hpp>
#include "Typing.h"

int main() {
//    srand(time(nullptr));
//    sf::err().rdbuf(nullptr);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({500, 500, 32}, "SFML Typing", sf::Style::Close, settings);
    window.setFramerateLimit(30);
    window.setVerticalSyncEnabled(false);

    Typing typing;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            typing.addEventHandler(window, event);
        }
        window.clear(sf::Color(sf::Color::Black));
        window.draw(typing);
        window.display();
        typing.update();
    }

    return 0;
}
