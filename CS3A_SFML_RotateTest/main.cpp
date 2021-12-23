#include <iostream>
#include <SFML/Graphics.hpp>
#include "Card.h"

int main() {
    sf::err().rdbuf(NULL);
    srand(time(nullptr));
    sf::Vector2u windowSize(720, 480);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    sf::RenderWindow window({windowSize.x, windowSize.y, 32}, "Test", sf::Style::Close, settings);
    window.setFramerateLimit(60);

    Card c1;

//    c1.setScale(2, 2);
    c1.setOrigin(c1.getBounds().width / 2, c1.getBounds().height / 2);
    c1.setPosition(windowSize.x / 2, windowSize.y / 2);
    c1.rotate(1.f);


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(c1);
        window.display();
        c1.rotate(1.f);
    }

    return 0;
}