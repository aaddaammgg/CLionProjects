#include <iostream>

int main() {
    int *ip = new int;
    ip = new int[5];

    int* *arr = new int*[5];

    for (int i = 0; i < 5; i++) {
        arr[i] = new int[5];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            //arr[i][j] = i + j;
            *( *(arr + i) + j ) = i + j;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout.width(4);
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
