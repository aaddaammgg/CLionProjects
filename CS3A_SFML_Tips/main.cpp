#include <iostream>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Screen.h"

void bounce(sf::Vector2u windowSize, sf::CircleShape &ball);

int main() {
    srand(time(nullptr));
    sf::err().rdbuf(NULL);
    sf::Vector2u windowSize(720, 480);

    sf::RenderWindow window({windowSize.x, windowSize.y, 32}, "Test");
    window.setFramerateLimit(60);

    Screen s1("img.jpeg", "Hide", "Awesome", windowSize);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            s1.eventHandler(window, event);
        }
        s1.update();
        window.clear(sf::Color::Black);
        window.draw(s1);
        window.display();
    }

    return 0;
}