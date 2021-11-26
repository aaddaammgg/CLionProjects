#include <iostream>
#include "NamedVector.h"

int main() {
    NamedVector<int> v;

    v.push_back(9);
    v.getName();

    std::cout << v;
    return 0;
}