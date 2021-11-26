//
// Created by Quantum on 9/22/2021.
//

#include "Dynamic_2D_Array.h"

int** createArray(int rows, int cols) {
    int* *temp = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        *(temp + i) = new int[cols];
    }

    return temp;
}

void fillArray(int** arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *( *(arr + i) + j ) = 0;
        }
    }
}

void resize(int** arr, int row, int col) {
    int** oldArr = arr;
    int** newArr = createArray(row * 2, col * 2);
    fillArray(newArr, row * 2, col * 2);


    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *( *(newArr + i) + j ) = *( *(arr + i) + j );
        }
    }

    //deleteArray(arr, row);
    //arr = newArr;
}

void deleteArray(int** arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[] *(arr + i);
    }
    delete[] arr;
}

void printArray(int** arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << *( *(arr + i) + j ) << std::endl;
        }
    }
}