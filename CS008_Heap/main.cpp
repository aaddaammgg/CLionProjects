#include <iostream>
#include "Heap.h"

int main() {
    Heap<int> h;

    h.push(2);
    h.push(5);
    h.push(7);

    std::cout << h.top() << std::endl;

    h += 10;

    std::cout << h.top() << std::endl;

    h.pop();

    std::cout << h.top() << std::endl;

    return 0;
}
