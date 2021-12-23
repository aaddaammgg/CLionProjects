#include <iostream>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "SFMLSceneSwitcher.h"

void draw(SFMLSceneSwitcher& scenes, sf::RenderWindow& window);

//sf::RectangleShape dot;


int main() {
    srand(time(nullptr));
    sf::err().rdbuf(nullptr);
    std::cout << "Time: " << time(nullptr) << std::endl;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT), 32}, WINDOW_TITLE, sf::Style::Close, settings);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(false);
    std::cout << "Time: " << time(nullptr) << std::endl;

    SFMLSceneSwitcher scenes;

    bool isEvent = false;

//    dot.setSize({2, 2});
//    dot.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
//    dot.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            isEvent = true;
            scenes.eventHandler(window, event);
            draw(scenes, window);
        }

        if (!isEvent) {
            draw(scenes, window);
        }
        isEvent = false;
    }

    return 0;
}

void draw(SFMLSceneSwitcher& scenes, sf::RenderWindow& window) {
    scenes.update(window);
    window.clear(sf::Color(WINDOW_BACKGROUND_COLOR));
    window.draw(scenes);
//    window.draw(dot);
    window.display();
}
