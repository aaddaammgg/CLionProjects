#include <iostream>
#include <ctime>

int main() {
    srand(time(nullptr));

    int min = 3;
    int max = 10;

    std::cout << rand() << std::endl;
    std::cout << min + (rand() % (max - min + 1) ) << std::endl;
    return 0;
}
