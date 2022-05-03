//
// Created by Adam G. on 5/2/22.
//

#include "LogoMaker.h"

void LogoMaker::run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    unsigned int WIDTH = 1280 * .8;
    unsigned int HEIGHT = 800 * 1;

    renderWindow.create({WIDTH, HEIGHT, 32}, "Logo Maker", sf::Style::Default, settings);
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

    displayLogo.setPosition(0, 55);
    displayLogo.setSize({static_cast<float>(WIDTH), 300});

    logoText.setLabel("Text: ");
    logoText.setLabelSize(29);
    logoText.setLabelColor(sf::Color::White);

    sf::Vector2f lastPosition = displayLogo.getPosition();
    sf::Vector2f lastSize = displayLogo.getSize();

    logoText.setSize({static_cast<float>(WIDTH) - 25, 30});
    logoText.setPosition(10, lastPosition.y + lastSize.y + 15);

    logoText.setCallBack([&](const std::string& str, bool isDelete) {
        if (isDelete) {
            std::cout << "delete" << std::endl;
        } else {
            std::cout << str[str.size()-1] << std::endl;
        }
    });

    lastPosition = logoText.getPosition();
    lastSize = logoText.getSize();

    float sliderWidth = static_cast<float>(WIDTH / 2.0) - 20 - 50;

    textOpacity.setLabel("Text Opacity");
    textOpacity.setPosition({10, lastPosition.y + lastSize.y + 15});
    textOpacity.setSize({sliderWidth,10});
    textOpacity.setMinMax({0, 255});

    lastPosition = textOpacity.getPosition();
    lastSize = textOpacity.getSize();

    textXAxis.setLabel("Text X-Axis");
    textXAxis.setPosition({10, lastPosition.y + lastSize.y + 15});
    textXAxis.setSize({sliderWidth,10});
    textXAxis.setMinMax({0, displayLogo.getSize().x});

    lastPosition = textXAxis.getPosition();
    lastSize = textXAxis.getSize();

    textYAxis.setLabel("Text Y-Axis");
    textYAxis.setPosition({10, lastPosition.y + lastSize.y + 15});
    textYAxis.setSize({sliderWidth,10});
    textYAxis.setMinMax({0, displayLogo.getSize().y});

    lastPosition = textYAxis.getPosition();
    lastSize = textYAxis.getSize();

    textFontSize.setLabel("Text Font Size");
    textFontSize.setPosition({10, lastPosition.y + lastSize.y + 15});
    textFontSize.setSize({sliderWidth,10});
    textFontSize.setMinMax({6, 128});

    lastPosition = textFontSize.getPosition();
    lastSize = textFontSize.getSize();

    shadowOpacity.setLabel("Shadow Opacity");
    shadowOpacity.setPosition({10, lastPosition.y + lastSize.y + 15});
    shadowOpacity.setSize({sliderWidth,10});
    shadowOpacity.setMinMax({0, 255});

    lastPosition = shadowOpacity.getPosition();
    lastSize = shadowOpacity.getSize();

    shadowXAxis.setLabel("Shadow X-Axis");
    shadowXAxis.setPosition({10, lastPosition.y + lastSize.y + 15});
    shadowXAxis.setSize({sliderWidth,10});
    shadowXAxis.setMinMax({0, displayLogo.getSize().x});

    lastPosition = shadowXAxis.getPosition();
    lastSize = shadowXAxis.getSize();

    shadowYAxis.setLabel("Shadow Y-Axis");
    shadowYAxis.setPosition({10, lastPosition.y + lastSize.y + 15});
    shadowYAxis.setSize({sliderWidth,10});
    shadowYAxis.setMinMax({0, displayLogo.getSize().y});

    lastPosition = shadowYAxis.getPosition();
    lastSize = shadowYAxis.getSize();

    shadowSkew.setLabel("Shadow Skew");
    shadowSkew.setPosition({10, lastPosition.y + lastSize.y + 15});
    shadowSkew.setSize({sliderWidth,10});
    shadowSkew.setMinMax({0, displayLogo.getSize().y});

    components.push_back(&shadowSkew);
    components.push_back(&shadowYAxis);
    components.push_back(&shadowXAxis);
    components.push_back(&shadowOpacity);

    components.push_back(&textFontSize);
    components.push_back(&textYAxis);
    components.push_back(&textXAxis);
    components.push_back(&textOpacity);

    components.push_back(&logoText);
    components.push_back(&displayLogo);
    components.push_back(&menuBar);

    bool isEvent = false;

    while (renderWindow.isOpen()) {
        sf::Event event{};
        while (renderWindow.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    renderWindow.close();
                    break;
                case sf::Event::Resized: {
                    unsigned int newWIDTH = event.size.width;
                    unsigned int newHEIGHT = event.size.height;

                    if (WIDTH * newHEIGHT > newWIDTH * HEIGHT) {
                        newHEIGHT = (newWIDTH * HEIGHT) / WIDTH;
                    } else {
                        newWIDTH = (newHEIGHT * WIDTH) / HEIGHT;
                    }

                    renderWindow.setSize({newWIDTH, newHEIGHT});
                    break;
                }
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

    window.clear(sf::Color(sf::Color::Black));

    for (auto & component : components) {
        window.draw(*component);
    }
    window.display();
}