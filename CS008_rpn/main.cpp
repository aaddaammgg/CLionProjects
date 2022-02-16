#include <iostream>
#include "RPN.h"

int main() {
    std::cout << RPN::infixToPostFix("5+(3*2)+4-5") << "  --> " << RPN::solvePostFix("532*+4+5-") << std::endl << std::endl;

    std::cout << "234*+      --> " << RPN::solvePostFix("234*+") << std::endl;
    std::cout << "23*73/+    --> " << RPN::solvePostFix("23*73/+") << std::endl;
    std::cout << "342+*5*    --> " << RPN::solvePostFix("342+*5*") << std::endl;

    return 0;
}
