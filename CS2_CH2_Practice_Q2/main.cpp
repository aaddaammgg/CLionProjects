#include <iostream>

int main() {
    double base, newNumber;
    int exponent;
    bool isReciprocal = false;
    char repeat;

    std::cout << "Please input the base number:" << std::endl;
    std::cin >> base;
    newNumber = base;
    std::cout << "Please input the exponent:" << std::endl;
    std::cin >> exponent;

    if (exponent < 0) {
        exponent *= -1; // we didnt learn to use absolute value yet
        isReciprocal = true;
    }
    while (exponent > 1) {
        newNumber *= base;
        exponent--;
    }
    if (exponent == 0) {
        newNumber = 1;
    }

    if (isReciprocal) {
        newNumber = 1 / newNumber;
    }

    std::cout << std::endl << "Answer: " << newNumber;

    std::cout << std::endl << "Would you like to repeat this program? Y/N" << std::endl;
    std::cin >> repeat;

    if (repeat == 'Y' || repeat == 'y') {
        std::cout << std::endl << std::endl;
        main();
    }
    return 0;
}
