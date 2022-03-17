#include <iostream>

int main() {
    char input;
    bool repeat;

    std::cout << "Hello!" << std::endl;

    do {
        repeat = false;
        std::cout << "Are you having a good day? Y/N" << std::endl;
        std::cin >> input;

        if (input == 'Y' || input == 'y') {
            std::cout << "I'm glad to hear that." << std::endl;
        } else if (input == 'N' || input == 'n') {
            std::cout << "I hope your day gets better soon." << std::endl;
        } else {
            repeat = true;
        }
    } while (repeat);

    return 0;
}
