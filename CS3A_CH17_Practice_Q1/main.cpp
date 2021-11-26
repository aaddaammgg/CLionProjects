#include <iostream>

template <class T>
int indexOf(T array[], int size, T value);

int main() {
    char c[50] = {'H', 'e', 'l', 'l', 'o'};
    int i[50] = {5, 6, 7, 8, 9};

    std::cout << indexOf(c, 5, 'H') << std::endl;
    std::cout << indexOf(c, 5, 'h') << std::endl;
    std::cout << indexOf(i, 5, 1) << std::endl;
    std::cout << indexOf(i, 5, 5) << std::endl;
    return 0;
}

template <class T>
int indexOf(T array[], int size, T value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}