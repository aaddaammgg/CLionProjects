#include <iostream>
#include <vector>
#include "Shuffle.h"

int main() {

    std::vector<int> v = { 1, 2, 3, 4, 5 };

    for (auto i : v) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    Shuffle<int, std::vector<int>>::shuffle(v);

    for (auto i : v) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}
