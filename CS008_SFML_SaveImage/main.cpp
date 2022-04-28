#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
//    srand(time(nullptr));
//    sf::err().rdbuf(nullptr);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window({720, 480, 32}, "SFML TEMPLATE", sf::Style::Close, settings);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(false);

    sf::RectangleShape square;
    square.setSize({100, 100});
    square.setPosition({10, 10});

    sf::CircleShape circle;
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Blue);

    sf::RenderTexture texture;
    texture.create(720,480, 32);

    sf::Sprite sprite;
    sprite.setTexture(texture.getTexture());


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                sf::Image img = texture.getTexture().copyToImage();
                img.saveToFile("MyTexture.png");
            }
        }

        texture.clear(sf::Color::Black);
        texture.draw(square);
        texture.draw(circle);
        texture.display();

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
