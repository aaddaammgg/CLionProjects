//
// Created by Adam G. on 5/2/22.
//

#include "LogoMaker.h"

void LogoMaker::run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    renderWindow.create({1280, 800, 32}, "Logo Maker", sf::Style::Close, settings);
    renderWindow.setFramerateLimit(60);
    renderWindow.setVerticalSyncEnabled(false);

    MenuItem menuFile("File");
    menuFile.setSize({250, 50});
    menuFile.addItem("New");
    menuFile.addItem("Exit", [&](const std::string& str) {
        std::cout << str << std::endl;
        renderWindow.close();
    });

    MenuItem menuEdit("Edit");
    menuEdit.setSize({250, 50});
    menuEdit.addItem("Exit", [&](const std::string& str) {
        std::cout << str << std::endl;
        renderWindow.close();
    });

    menuBar.addItem(menuFile);
    menuBar.addItem(menuEdit);

    logoText.setSize({200, 30});
    logoText.setPosition(10,55);

    std::vector<GUIComponent*> components;
    components.push_back(&menuBar);
    components.push_back(&logoText);

    bool isEvent = false;

    while (renderWindow.isOpen()) {
        sf::Event event{};
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderWindow.close();
            }
            isEvent = true;
            for (auto & component : components) {
                component->addEventHandler(renderWindow, event);
            }
            draw(components, renderWindow);
        }

        if (!isEvent) {
            draw(components, renderWindow);
        }
        isEvent = false;
    }
}

void LogoMaker::draw(std::vector<GUIComponent *> &components, sf::RenderWindow &window) {
    for (auto & component : components) {
        component->update();
    }
    window.clear(sf::Color(sf::Color::White));
    for (auto & component : components) {
        window.draw(*component);
    }
    window.display();
}