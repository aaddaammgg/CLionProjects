#include <iostream>
#include "Month.h"

int main() {
    Month testMonth('J','a','n');
    std::cout << testMonth.getMonthAsLetters() << std::endl;
    std::cout << testMonth.getMonth() << std::endl;
    Month testMonth2(12);
    std::cout << testMonth2.getMonthAsLetters() << std::endl;
    std::cout << testMonth2.getMonth() << std::endl;
    return 0;
}
