#include <iostream>
#include <iomanip>

#define spacing 5

int main() {
    int min = 3, max = 28;

    int x = min;

    if (x % 2 == 0) {
        x++;
    }

    for (int i = min; i <= max; i++) {
        std::cout << std::setw(spacing) << i;

        if (x <= max) {
            std::cout << std::setw(spacing) << x << std::setw(spacing) << i + x;
            x += 2;
        } else {
            std::cout << std::setw(spacing * 2) << i;
        }

        std::cout << std::endl;
    }

    return 0;
}


// std::cout << std::setw(5) << ((x <= max) ? std::to_string(x) : "") << std::setw(5) << i + x;
