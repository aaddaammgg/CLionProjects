#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    list.push_back(2);
    std::cout << list << std::endl;

    list += 3;
    std::cout << list << std::endl;

    list.push_front(4);
    std::cout << list << std::endl;

    list.insertBefore(5, 2);
    std::cout << list << std::endl;

    list.insertAfter(8, 5);
    std::cout << list << std::endl;

    return 0;
}
