/*
 * Adam Gonzalez
 * Project 1 - Simulating Gates
 * Program works
 */

#include <iostream>
#include <fstream>

const int MAX = 8;

void add(const char memory[MAX], const char accum[MAX], char result[MAX + 1]);
void complement(char result[], const int size);

void add(const char memory[MAX], const char accum[MAX], char result[MAX + 1]) {
    char carry = 'D';

    for (int i = MAX - 1; i >= 0; i--) {
        if (accum[i] == 'L' && memory[i] == 'L') {
            result[i + 1] = carry;
            carry = 'L';
        } else if (accum[i] != memory[i]) {
            result[i + 1] = carry == 'D' ? 'L' : 'D';
        } else {
            result[i + 1] = carry;
            carry = 'D';
        }
    }

    result[0] = carry;
}

void complement(char result[], const int size) {
    for (int i = 0; i < size; i++) {
        result[i] = result[i] == 'D' ? 'L' : 'D';
    }
}

int main() {
    std::cout << "Adam Gonzalez (10275803)" << std::endl << std::endl;

    std::ifstream file("P1Data.txt");

    if (file.fail()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

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

    char result[MAX + 1];

    add(memory, accum, result);

    for (int i = 0; i < MAX + 1; i++) {
        std::cout << result[i];
    }

    std::cout << std::endl << std::endl;

    // EXTRA CREDIT:

    char increment[MAX] = {'D','D','D','D','D','D','D','L'};

    complement(accum, MAX);

    add(increment, accum, result);

    // Discard first bit in result
    for (int i = 0; i < MAX; i++) {
        accum[i] = result[i + 1];
    }

    add(memory, accum, result);

    for (int i = 0; i < MAX + 1; i++) {
        std::cout << result[i];
    }

    return 0;
}