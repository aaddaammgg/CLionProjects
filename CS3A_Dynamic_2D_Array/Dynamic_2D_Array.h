//
// Created by Quantum on 9/22/2021.
//

#ifndef CS3A_DYNAMIC_2D_ARRAY_DYNAMIC_2D_ARRAY_H
#define CS3A_DYNAMIC_2D_ARRAY_DYNAMIC_2D_ARRAY_H

#include <iostream>

int** createArray(int rows, int cols);
void fillArray(int** arr, int row, int col);
void resize(int** arr, int row, int col);
void deleteArray(int** arr, int row);
void printArray(int** arr, int row, int col);

#endif //CS3A_DYNAMIC_2D_ARRAY_DYNAMIC_2D_ARRAY_H
