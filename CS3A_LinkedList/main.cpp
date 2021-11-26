#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> l1;

    for (int i = 0; i < 10; i++) {
        l1.push_front(i);
    }

    std::cout << l1 << std::endl;

    ////////////////////////////////////

    LinkedList<int> l2;

    for (int i = 0; i < 10; i++) {
        l2.push_back(i);
    }

    std::cout << l2 << std::endl;

    return 0;
}
