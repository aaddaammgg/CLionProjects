//
// Created by Quantum on 5/14/2023.
//

#include <chrono>
#include <cmath>
#include "Application.h"

void Application::run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({500, 500, 32}, "Kings Corner", sf::Style::Close, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

    std::vector<GUIAdapter*> components;

    GUI_Circle circle(sf::Color::Green);

    circle.setDraggable(true);
    circle.setPosition(0, 0);

    GUI_Circle circle2(sf::Color::Red);
    circle2.setDraggable(true);
    circle2.setPosition(125, 0);

    components.push_back(&circle);
    components.push_back(&circle2);

    float fps;
    sf::Clock clock;
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time previousTime2 = previousTime;
    sf::Time currentTime;

    sf::Font font;
    if (!font.loadFromFile("resources/fonts/Roboto-Bold.ttf")) {
        std::cout << "Font not found" << std::endl;
    }

    sf::Text fpsText;
    fpsText.setPosition(5, 5);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setStyle(sf::Text::Bold | sf::Text::Underlined);


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            for (auto* component : components) {
                component->addEventHandler(window, event);
            }
        }

        for (auto* component : components) {
            component->update(window);
        }

        window.clear(sf::Color(sf::Color::Black));
        for (auto* component : components) {
            window.draw(*component);
        }
        window.draw(fpsText);
        window.display();

        currentTime = clock.getElapsedTime();
        if (currentTime.asMilliseconds() - previousTime2.asMilliseconds() >= 50) {
            fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
            fpsText.setString("FPS: " + std::to_string(std::floor(fps)));
            previousTime2 = currentTime;
        }
        previousTime = currentTime;


    }
}
