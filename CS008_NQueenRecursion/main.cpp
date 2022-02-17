#include <iostream>
#include "NQueen.h"
#include "Timer.h"

int main() {
    Timer t;
    t.start();

    NQueen a(5);

    t.end();

    std::cout << "It took " << t.getDuration() << " seconds" << std::endl;
    return 0;
}
