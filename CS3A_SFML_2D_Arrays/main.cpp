#include <iostream>
#include <SFML/Graphics.hpp>

#include "SFML_2D_Array.h"

void print();

int main() {
    sf::Vector2u windowSize(720, 480);

    int rows = 1, cols = 1;
    sf::RectangleShape** arr = createArray(rows, cols);
    fillArray(arr, rows, cols);

    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y, 32), "2D Arrays");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            deleteArray(arr, rows);
            if (event.type == sf::Event::KeyPressed) {
                if ((event.key.code == sf::Keyboard::Up) && (cols > 1)) {
                    cols--;
                } else if (event.key.code == sf::Keyboard::Down) {
                    cols++;
                } else if ((event.key.code == sf::Keyboard::Left) && (rows > 1)) {
                    rows--;
                } else if (event.key.code == sf::Keyboard::Right) {
                    rows++;
                }
            }
            arr = createArray(rows, cols);
            fillArray(arr, rows, cols);
        }

        window.clear(sf::Color::Black);

        draw(window, arr, rows, cols);
        window.display();
    }

    return 0;
}