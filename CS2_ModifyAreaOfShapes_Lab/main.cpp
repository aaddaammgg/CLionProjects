#include <iostream>

int main() {
    char shape;
    double area, length, width, base, height, radius, pi = 3.143159;

    std::cout << "Choose a shape to calculate the area:" << std::endl;
    std::cout << "(r)ectangle" << std::endl;
    std::cout << "(t)riangle" << std::endl;
    std::cout << "(c)ircle" << std::endl;
    std::cin >> shape;

    if (shape == 'r' || shape == 'R') { // Rectangle
        std::cout << std::endl << "What is the length?" << std::endl;
        std::cin >> length;
        std::cout << std::endl << "What is the width?" << std::endl;
        std::cin >> width;

        area = length * width;
        std::cout << std::endl << "The area of the rectangle is " << area << std::endl;
    } else if (shape == 't' || shape == 'T') { // Triangle
        std::cout << std::endl << "What is the base?" << std::endl;
        std::cin >> base;
        std::cout << std::endl << "What is the height?" << std::endl;
        std::cin >> height;

        area = (base / 2) * height;
        std::cout << std::endl << "The area of the triangle is " << area << std::endl;
    } else if (shape == 'c' || shape == 'C') { // Circle
        std::cout << std::endl << "What is the radius?" << std::endl;
        std::cin >> radius;

        area = pi * (radius * radius);
        std::cout << std::endl << "The area of the circle is " << area << std::endl;
    } else {
        std::cout << std::endl << "Invalid input. Program will now exit." << std::endl;
    }

    return 0;
}
