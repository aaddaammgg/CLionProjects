#include <iostream>

#include "Dynamic_2D_Array.h"

int main() {
    int rows = 2, cols = 2;
    int** arr = createArray(rows, cols);
    fillArray(arr, rows, cols);
    printArray(arr, rows, cols);
    resize(arr, rows, cols);
    deleteArray(arr, rows);
    printArray(arr, rows, cols);
    return 0;
}
