#include <iostream>

void addOne(int *ptrNum);

int main() {
    int ptrNum = 0;

    std::cout << ptrNum << std::endl;
    addOne(&ptrNum);
    std::cout << ptrNum << std::endl;
    return 0;
}

void addOne(int *ptrNum) {
    (*ptrNum)++;
}