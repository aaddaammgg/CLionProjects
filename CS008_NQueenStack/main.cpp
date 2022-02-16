#include <iostream>
#include "NQueens.h"

int main() {
    NQueens n;
    n.solve(3);
    n.print();
    n.solve(4);
    n.print();
    n.solve(5);
    n.print();
    return 0;
}
