//
// Created by Adam Gonzalez on 9/21/2021.
//

#include "SFML_2D_Array.h"

sf::RectangleShape** createArray(int rows, int cols) {
    sf::RectangleShape* *temp = new sf::RectangleShape*[rows];

    for (int i = 0; i < rows; ++i) {
        *(temp + i) = new sf::RectangleShape[cols];
    }

    return temp;
}

sf::RectangleShape newRectangleShape(float x, float y, sf::Color color) {
    sf::RectangleShape rectangle;
    sf::Vector2f size(5,5);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    rectangle.setPosition(15 + x, 15 + y);

    return rectangle;
}

void fillArray(sf::RectangleShape** arr, int row, int col, sf::Color color) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *( *(arr + i) + j ) = newRectangleShape(20 * i, 20 * j, color);
        }
    }
}

void deleteArray(sf::RectangleShape** arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[] *(arr + i);
    }
    delete[] arr;
}

void draw(sf::RenderWindow& window, sf::RectangleShape** arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            window.draw(*( *(arr + i) + j ));
        }
    }
}