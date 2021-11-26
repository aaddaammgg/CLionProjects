#include <iostream>
#include "Complex.h"

int main() {
    Complex n1(3, 2), n2(4, -3);
    std::cout << "x: " << n1 << std::endl;
    std::cout << "y: " << n2 << std::endl;

    std::cout << "(x + y): " << n1 + n2 << std::endl;
    std::cout << "(x - y): " << n1 - n2 << std::endl;
    std::cout << "(x * y): " << n1 * n2 << std::endl;
    std::cout << "     ==: " << (n1 == n2) << std::endl;

    return 0;
}
