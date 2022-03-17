#include <iostream>

void swapFrontBack(int array[], int size);
void outputArray(int array[], int size);

int main() {
    const int size = 6;
    int array[size] = { 2, 1, 1, 1, 3, 3 };

    swapFrontBack(array, size);
    outputArray(array, size);

    return 0;
}

void outputArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << " ";
}

void swapFrontBack(int array[], int size) {
    if (size > 0) {
        int temp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = temp;
    } else {
        std::cout << "ERROR";
    }
}