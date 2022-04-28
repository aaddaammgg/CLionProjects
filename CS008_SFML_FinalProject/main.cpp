#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextInput.h"
#include "DropdownMenu.h"
#include "MenuItem.h"
#include "MenuBar.h"
#include "Slider.h"

void draw(std::vector<GUIComponent*>& components, sf::RenderWindow& window);

int main() {
    srand(time(nullptr));
    sf::err().rdbuf(nullptr);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({700, 700, 32}, "SFML Typing", sf::Style::Close, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

//    TextInput typing;
//    TextInput typing2;
//
//    typing.setPosition(50,50);
//    typing.setSize({250, 50});
//    typing.setLabel("User:");
//    typing.setLabelSize(50);
//
//    typing2.setPosition(50,120);
//    typing2.setSize({400, 50});
//
//    DropdownMenu dm;
//    dm.setPosition(50, 180);
//    dm.setSize({250, 50});
//    dm.setScale({1.5, 1.5});
//
//    dm.setCallBack([&](const std::string& str) {
//        std::cout << str << std::endl;
//
//        if (str == "Exit") {
//            window.close();
//        }
//    });
//
//    dm.addItem("Banana");
//    dm.addItem("Apple");
//    dm.addItem("Orange");
//    dm.addItem("Lemon");
//    dm.addItem("Exit");

    MenuItem menuFile("File");
    menuFile.setSize({250, 50});
    menuFile.addItem("New");
    menuFile.addItem("Exit", [&](const std::string& str) {
        std::cout << str << std::endl;
        window.close();
    });

    MenuItem menuEdit("Edit");
    menuEdit.setSize({250, 50});
    menuEdit.addItem("New 1");
    menuEdit.addItem("New 2");
    menuEdit.addItem("New 3");
    menuEdit.addItem("New 4");
    menuEdit.addItem("Exit", [&](const std::string& str) {
        std::cout << str << std::endl;
        window.close();
    });

    MenuBar menuBar;

    menuBar.addItem(menuFile);
    menuBar.addItem(menuEdit);

    Slider slider;
    slider.setSize({200, 20});
    slider.setPosition({100, 300});



    std::vector<GUIComponent*> components;
//    components.push_back(&typing);
//    components.push_back(&typing2);
//    components.push_back(&dm);
//    components.push_back(&menuFile);
    components.push_back(&menuBar);
    components.push_back(&slider);

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