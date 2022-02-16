#include <iostream>
#include <algorithm>
#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList<int> l;

    std::cout << "Size of List: " << l.getSize() << std::endl << std::endl;

    std::cout << "l.push_back(2);" << std::endl;
    l.push_back(2);
    std::cout << l << std::endl << std::endl;

    std::cout << "l += 3;" << std::endl;
    l += 3;
    std::cout << l << std::endl << std::endl;

    std::cout << "l.push_front(4);" << std::endl;
    l.push_front(4);
    std::cout << l << std::endl << std::endl;

    std::cout << "l.insertBefore(5, 2);" << std::endl;
    l.insertBefore(5, 2);
    std::cout << l << std::endl << std::endl;

    std::cout << "l.insertAfter(8, 5);" << std::endl;
    l.insertAfter(8, 5);
    std::cout << l << std::endl << std::endl;

    std::cout << "Size of List: " << l.getSize() << std::endl;

//    l.push_back(4);

    DoublyLinkedList<int> copyL = l; // assignment operator and copy constructor


    std::reverse(l.begin(), l.end());
    std::swap(l.front(), l.back());
    std::cout << std::count(l.begin(), l.end(), 4) << std::endl;

    std::cout << l << std::endl << std::endl;
    std::cout << copyL << std::endl << std::endl;

//    for (auto i : l) {
//        std::cout << i;
//    }

//    for (it = l.begin(); it != l.end(); ++it){
//        std::cout << *it;
//    }

    return 0;
}
