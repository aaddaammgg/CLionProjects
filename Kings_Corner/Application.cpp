//
// Created by Quantum on 5/14/2023.
//

#include "Application.h"

void Application::run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({500, 500, 32}, "Kings Corner", sf::Style::Close, settings);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(false);

//    std::vector<GUIAdapter*> components;

    GUI_Circle circle(sf::Color::Red);
//    circle.setDraggable(true);
    circle.setPosition(0, 20);

    GUI_Circle circle2(sf::Color::Green);
//    circle2.setDraggable(true);
    circle2.setPosition(125, 20);

    GUI_Circle circle3(sf::Color::Blue);
//    circle3.setDraggable(true);
    circle3.setPosition(250, 20);

//    components.push_back(&circle);
//    components.push_back(&circle2);
//    components.push_back(&circle3);

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
    fpsText.setCharacterSize(18);
    fpsText.setStyle(sf::Text::Bold | sf::Text::Underlined);


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            MouseEvents::eventHandler(window, event);

//            for (auto* component : GUIAdapter::components) {
//                component->addEventHandler(window, event);
//            }
        }

        for (auto* component : GUIAdapter::components) {
            component->update(window);
        }

        window.clear(sf::Color(sf::Color::Black));
        for (auto* component : GUIAdapter::components) {
            window.draw(*component);
        }
        window.draw(fpsText);
        window.display();

        currentTime = clock.getElapsedTime();
        if (currentTime.asMilliseconds() - previousTime2.asMilliseconds() >= 50) {
            fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
            fpsText.setString("FPS: " + std::to_string((int)fps));
            previousTime2 = currentTime;
        }
        previousTime = currentTime;


    }
}
