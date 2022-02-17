#include <iostream>
#include "NQueens.h"
#include "Timer.h"

int main() {
    Timer t;
    t.start();

    NQueens n;
    n.solve(5);
    n.print();

    t.end();

    std::cout << "It took " << t.getDuration() << "seconds" << std::endl;
    return 0;
}
