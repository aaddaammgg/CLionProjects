#include <iostream>
#include <ctime>

void randomFill(int array[], int size);
void printArray(int array[], int size);
void selectionSort(int array[], int size);
void bubbleSort(int array[], int size);
void swap(int &a, int &b);

int main() {
    srand(time(0));
    const int size = 20;
    int array[size];
    randomFill(array, size);
    printArray(array, size);
    bubbleSort(array, size);
    printArray(array, size);
    return 0;
}

void randomFill(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";
}

void selectionSort(int array[], int size) {
    int index, minValue;

    for (int i = 0; i < size; i++) {
        minValue = array[i];
        index = i;

        for (int j = i; j < size; j++) {
            if (array[j] < minValue) {
                minValue = array[j];
                index = j;
            }
        }

        swap(array[i], array[index]);
    }
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] > array[i + 1]) {
            swap(array[i], array[i + 1]);
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}