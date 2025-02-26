/*
 * Adam Gonzalez
 * Project 1 - Simulating Gates
 * Program works
 */

#include <iostream>
#include <fstream>

int main() {
    std::cout << "Adam Gonzalez (10275803)" << std::endl << std::endl;

    std::ifstream file("P1Data.txt");

    if (file.fail()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    const int MAX = 8;

    char accum[MAX];
    char memory[MAX];

    std::cout << ' ';

    for (int i = 0; i < MAX; i++) {
        file >> accum[i];
        std::cout << accum[i];
    }

    std::cout << std::endl << ' ';

    for (int i = 0; i < MAX; i++) {
        file >> memory[i];
        std::cout << memory[i];
    }

    std::cout << std::endl;

    file.close();

    char carry = 'D';
    char result[MAX + 1];

    for (int i = MAX - 1; i >= 0; i--) {
        if (accum[i] == 'L' && memory[i] == 'L') {
            result[i + 1] = carry;
            carry = 'L';
        } else if (accum[i] != memory[i]) {
            if (carry == 'D') {
                result[i + 1] = 'L';
            } else {
                result[i + 1] = 'D';
            }
        } else {
            result[i + 1] = carry;
            carry = 'D';
        }
    }

    result[0] = carry;

    for (int i = 0; i < MAX + 1; i++) {
        std::cout << result[i];
    }

    return 0;
}