#include <iostream>

int countNum2s(const int array[], int size);

int main() {
    const int size = 6;
    int array[size] = { 2, 1, 1, 1, 3, 3 };
	int count = countNum2s(array, size);

	std::cout << "Number of 2's: " << count << "\n";

	return 0;
}

int countNum2s(const int array[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == 2) {
            count++;
        }
    }

    return count;
}