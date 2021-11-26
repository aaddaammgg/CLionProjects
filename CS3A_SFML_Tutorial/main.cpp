#include <iostream>
#include <SFML/Graphics.hpp>

void bounce(sf::Vector2u windowSize, sf::CircleShape &ball);

int main() {
    sf::err().rdbuf(NULL);
    srand(time(nullptr));
    sf::Vector2u windowSize(720, 480);

    sf::RenderWindow window({windowSize.x, windowSize.y, 32}, "Test");
    window.setFramerateLimit(60);
    sf::CircleShape ball;

    ball.setFillColor(sf::Color::Red);
    ball.setRadius(50);
    ball.setPosition(rand() % (windowSize.x - 100), rand() % (windowSize.y - 100));

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        bounce(windowSize, ball);

        window.clear(sf::Color::Black);
        window.draw(ball);
        window.display();
    }

    return 0;
}

float ix = 5;
float iy = 5;

void bounce(sf::Vector2u windowSize, sf::CircleShape &ball) {
    sf::Vector2f pos = ball.getPosition();

    float radius = ball.getRadius() * 2;

    float xix = pos.x + ix;
    float yiy = pos.y + iy;

    if (xix > windowSize.x - radius || xix < 0) {
        ix = -ix;
        ball.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }

    if (yiy > windowSize.y - radius || yiy < 0) {
        iy = -iy;
        ball.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }

    ball.move(ix, iy);
}
