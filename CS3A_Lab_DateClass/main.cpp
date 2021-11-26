#include <iostream>
#include "Date.h"

int main() {
    Date d;
    std::cout << d.getDate("YY-M-d") << std::endl;
    std::cout << d.getDate("MM d, YY") << std::endl;
    std::cout << d.getDate("m/d") << std::endl;

    Date d2(12, 25, 2021);
    std::cout << d2 << std::endl;
    std::cout << d2 + 1 << std::endl;
    std::cout << d2 - 2 << std::endl;

    d = d2;

    std::cout << d << std::endl;
    return 0;
}
