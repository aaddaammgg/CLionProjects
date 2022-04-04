#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextInput.h"
#include "DropdownMenu.h"

void draw(std::vector<GUIComponent*>& components, sf::RenderWindow& window);

int main() {
    srand(time(nullptr));
    sf::err().rdbuf(nullptr);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({700, 700, 32}, "SFML Typing", sf::Style::Close, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

    TextInput typing;
    TextInput typing2;

    typing.setPosition(50,50);
    typing.setSize({250, 50});
    typing.setLabel("User:");
    typing.setLabelSize(50);

    typing2.setPosition(50,120);
    typing2.setSize({400, 50});

    DropdownMenu dm;
    dm.setPosition(50, 180);
    dm.setSize({250, 50});
    dm.setScale({1.5, 1.5});

    dm.addItem("Banana");
    dm.addItem("Apple");
    dm.addItem("Orange");
    dm.addItem("Lemon");


    std::vector<GUIComponent*> components;
    components.push_back(&typing);
    components.push_back(&typing2);
    components.push_back(&dm);

    bool isEvent = false;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            isEvent = true;
            for (auto & component : components) {
                component->addEventHandler(window, event);
            }
            draw(components, window);
        }

        if (!isEvent) {
            draw(components, window);
        }
        isEvent = false;
    }

    return 0;
}

void draw(std::vector<GUIComponent*>& components, sf::RenderWindow& window) {
    for (auto & component : components) {
        component->update();
    }
    window.clear(sf::Color(sf::Color::White));
    for (auto & component : components) {
        window.draw(*component);
    }
    window.display();
}