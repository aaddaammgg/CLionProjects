#include <iostream>
#include "MyString.h"

int main() {
    MyString test("hi my name is");

    std::cout << test << std::endl;
    std::cin >> test;
    std::cout << test << std::endl;

    return 0;
}
