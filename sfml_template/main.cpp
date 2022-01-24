#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
//    srand(time(nullptr));
//    sf::err().rdbuf(nullptr);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({500, 500, 32}, "SFML TEMPLATE", sf::Style::Close, settings);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(false);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(250.f);

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

    return 0;
}
