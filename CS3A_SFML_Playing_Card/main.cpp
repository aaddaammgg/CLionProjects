#include <iostream>
#include <SFML/Graphics.hpp>
#include "Card.h"

int main() {
    sf::err().rdbuf(NULL);
    srand(time(nullptr));
    sf::Vector2u windowSize(400, 500);

    sf::RenderWindow window({windowSize.x, windowSize.y, 32}, "Test");
    window.setFramerateLimit(60);

    Card Card1("Ace", "Hearts");



    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(Card1);
        window.display();
    }

    return 0;
}