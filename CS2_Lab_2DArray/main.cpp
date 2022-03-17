#include <iostream>

int main() {
    int arr[1000][1000];
    int count = 0;
    for (int row = 0; row < 1000; row++) {
        for (int col = 0; col < 1000; col++) {
            count++;
            arr[row][col] = count;
        }
    }

    for (int row = 0; row < 1000; row++) {
        for (int col = 0; col < 1000; col++) {
            std::cout << arr[row][col] << " ";
        }
    }

    return 0;
}
