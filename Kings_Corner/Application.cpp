//
// Created by Quantum on 5/14/2023.
//

#include "Application.h"

void Application::run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({WINDOW_WIDTH, WINDOW_HEIGHT, 32}, WINDOW_TITLE, sf::Style::Close, settings);

    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(false);

//    std::vector<GUIAdapter*> components;

    GUI_Circle circle(sf::Color::Red);
    circle.enableState(IS_DRAGGABLE);
    circle.setPosition(0, 20);

    GUI_Circle circle2(sf::Color::Green);
    circle2.enableState(IS_DRAGGABLE);
    circle2.setPosition(125, 20);

    GUI_Circle circle3(sf::Color::Blue);
    circle3.enableState(IS_DRAGGABLE);
//    circle3.enableState(DISABLED);
    circle3.setPosition(250, 20);

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

    Deck deck;

    CardHand ch;

    SFMLCard card(&deck.dealCard());
    card.enableState(IS_DRAGGABLE);

    card.setPosition(100, 100);

    SFMLDeck sfmlDeck(&deck);
    sfmlDeck.setPosition(250, 250);

    GUIAdapter::components.push_back(&circle);
    GUIAdapter::components.push_back(&circle2);
    GUIAdapter::components.push_back(&circle3);
    GUIAdapter::components.push_back(&card);
    GUIAdapter::components.push_back(&sfmlDeck);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            MouseEvents::eventHandler(window, event);


            if (MouseEvents::mouseButtonReleased(false) && MouseEvents::lastSelected != nullptr) {
                auto* selected = (GUI_Circle*)MouseEvents::lastSelected;

                if (selected == &circle) {
                    BaseCard& bCard = deck.dealCard();
                    std::cout << bCard << std::endl;
                    card.setCard(&bCard);
                } else if (selected == &circle2) {
                    card.enableState(IS_HIDDEN);
                } else if (selected == &circle3) {
                    deck.shuffle();
                    card.disableState(IS_HIDDEN);
                }
            }

//            for (auto* component : GUIAdapter::components) {
//                component->addEventHandler(window, event);
//            }
        }

        for (auto* component : GUIAdapter::components) {
            component->update(window);
        }

        window.clear(sf::Color(WINDOW_BACKGROUND_COLOR));
        for (auto* component : GUIAdapter::components) {
            window.draw(*component);
        }
        window.draw(fpsText);
        window.display();

        currentTime = clock.getElapsedTime();
        if (currentTime.asMilliseconds() - previousTime2.asMilliseconds() >= 50) {
            fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
            fpsText.setString("FPS: " + std::to_string((int)fps) + " " + std::to_string(MouseEvents::selected != nullptr ? (uintptr_t)MouseEvents::selected : 0));
            previousTime2 = currentTime;
        }
        previousTime = currentTime;

    }
}
