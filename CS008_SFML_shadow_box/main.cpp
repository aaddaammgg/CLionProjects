#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextReflection.h"

int main() {
    sf::RenderWindow window({1200, 800, 32}, "Text Shadow Box", sf::Style::Close);
    window.setFramerateLimit(60);

    TextReflection tr("hello this is awesome!", "Roboto-Regular.ttf", 100);

    tr.setPosition(100, 50);
    tr.setTextColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(tr);
        window.display();
    }
    return 0;
}
