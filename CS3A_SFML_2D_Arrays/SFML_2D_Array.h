//
// Created by Adam Gonzalez on 9/21/2021.
//

#ifndef CS3A_SFML_2D_ARRAYS_SFML_2D_ARRAY_H
#define CS3A_SFML_2D_ARRAYS_SFML_2D_ARRAY_H

#include <SFML/Graphics.hpp>
sf::RectangleShape** createArray(int rows, int cols);
sf::RectangleShape newRectangleShape(float x, float y, sf::Color color);
void fillArray(sf::RectangleShape** arr, int row, int col, sf::Color color);
void deleteArray(sf::RectangleShape** arr, int row);
void draw(sf::RenderWindow& window, sf::RectangleShape** p, int row, int col);

#endif //CS3A_SFML_2D_ARRAYS_SFML_2D_ARRAY_H
