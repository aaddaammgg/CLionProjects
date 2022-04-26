//
// Created by Adam G. on 4/25/22.
//

#include "CrappyProgram.h"

CrappyProgram::CrappyProgram() {
    circle.setPosition({50, 50});
    square.setPosition({50, 200});
}

void CrappyProgram::run() {
    sf::RenderWindow window({720, 420, 32}, "PROGRAM");
    window.setFramerateLimit(30);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) &&
                sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                save();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) &&
                sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                load();
            }

            text.eventHandler(window, event);
            circle.eventHandler(window, event);
            square.eventHandler(window, event);
        }

        window.clear();
        window.draw(text);
        window.draw(circle);
        window.draw(square);
        window.display();
    }
}

void CrappyProgram::save() {
    std::ofstream fout;
    fout.open("crappyProgram.txt");

    fout << (std::string) text.getString() << std::endl;
    fout << text.getPosition().x << std::endl;
    fout << text.getPosition().y << std::endl;

    fout << circle.getRadius() << std::endl;
    fout << circle.getPosition().x << std::endl;
    fout << circle.getPosition().y << std::endl;

    fout << square.getFillColor().toInteger() << std::endl;
    fout << square.getPosition().x << std::endl;
    fout << square.getPosition().y << std::endl;

    fout.close();
}

void CrappyProgram::load() {
    std::ifstream fin;

    fin.open("crappyProgram.txt");
    if (fin.fail()) {
        exit(28);
    }

    std::string textStr;
    sf::Vector2f pos;

    fin >> textStr;
    fin >> pos.x;
    fin >> pos.y;

    text.setString(textStr);
    text.setPosition(pos);

    float circleRadius;
    fin >> circleRadius;
    fin >> pos.x;
    fin >> pos.y;
    circle.setRadius(circleRadius);
    circle.setPosition(pos);

    sf::Uint32 color;
    fin >> color;
    fin >> pos.x;
    fin >> pos.y;
    square.setFillColor(sf::Color(color));
    square.setPosition(pos);

    fin.close();
}
