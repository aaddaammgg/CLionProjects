#include <iostream>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "SFMLSceneSwitcher.h"

int main() {
    srand(time(nullptr));
    sf::err().rdbuf(nullptr);
    std::cout << "Time: " << time(nullptr) << std::endl;

    sf::RenderWindow window({static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT), 32}, WINDOW_TITLE, sf::Style::Close);
    window.setFramerateLimit(60);
    std::cout << "Time: " << time(nullptr) << std::endl;

    SFMLSceneSwitcher scenes;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            scenes.eventHandler(window, event);
        }
        scenes.update();
        window.clear(sf::Color(WINDOW_BACKGROUND_COLOR));
        window.draw(scenes);
        window.display();
    }

    return 0;
}