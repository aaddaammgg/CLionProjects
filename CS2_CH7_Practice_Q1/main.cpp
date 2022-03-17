#include <iostream>

bool firstLast2(const int array[], int size);

int main() {
    const int size = 6;
    int array[size] = { 2, 1, 1, 1, 3, 3 };
    bool firstLast = firstLast2(array, size);

    std::cout << "firstLast2: " << (firstLast ? "true" : "false") << "\n";

    return 0;
}

bool firstLast2(const int array[], int size) {
    if (array[0] == 2 || array[size - 1] == 2) {
        return true;
    }

    return false;
}
