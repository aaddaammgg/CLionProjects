#include <iostream>
#include <ctime>

int main() {
    std::cout << std::time(0) << std::endl;
    std::cout << std::time(NULL) << std::endl;
    std::cout << std::time(nullptr) << std::endl;
    return 0;
}
