#include <iostream>
#include <SFML/Graphics.hpp>
#include "BouncingObject.h"

int main() {
    srand(time(nullptr));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Object", sf::Style::Close, settings);
    window.setFramerateLimit(30);

//    BouncingObject<sf::CircleShape> ball;
    BouncingObject<sf::RectangleShape> ball;

    ball.shape().setSize({200, 100});
//    ball.shape().setRadius(150);
    ball.shape().setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ball.update(window);
        window.clear(sf::Color::Black);
        window.draw(ball);
        window.display();
    }

    return 0;
}