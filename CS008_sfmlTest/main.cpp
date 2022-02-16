#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window({1200, 800, 32}, "Test", sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}
