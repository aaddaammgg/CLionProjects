#include <iostream>
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800, 32), "Test");

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(100.f);

    sf::CircleShape triangle(80.f, 3);
    triangle.setFillColor(sf::Color::White);
    triangle.setPosition(300, 0);

    sf::CircleShape square(80.f, 4);
    square.setFillColor(sf::Color::White);
    square.setPosition(0, 300);

    sf::CircleShape octagon(80.f, 8);
    octagon.setFillColor(sf::Color::White);
    octagon.setPosition(0, 500);

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(300, 300);

    sf::ConvexShape convex;

    convex.setPointCount(5);

    convex.setPoint(0, sf::Vector2f(0, 0));
    convex.setPoint(1, sf::Vector2f(150, 10));
    convex.setPoint(2, sf::Vector2f(120, 90));
    convex.setPoint(3, sf::Vector2f(30, 100));
    convex.setPoint(4, sf::Vector2f(0, 50));

    convex.setPosition(500, 500);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            float x = circle.getPosition().x;
            float y = circle.getPosition().y;
            if (event.type == sf::Event::Closed){
                window.close();
            } else if(event.type == sf::Event::MouseWheelMoved) {
                if (event.mouseWheel.delta == 1) {
                    circle.setPosition(x, y - 5);
                } else {
                    circle.setPosition(x, y + 5);
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                circle.setPosition(x - 5, y);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                circle.setPosition(x + 5, y);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                circle.setPosition(x, y - 5);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                circle.setPosition(x, y + 5);
            }
        }
        window.clear(sf::Color::Green);
        window.draw(circle);
        window.draw(triangle);
        window.draw(square);
        window.draw(octagon);
        window.draw(convex);
        window.draw(rectangle);
        window.display();
    }
    return 0;
}
