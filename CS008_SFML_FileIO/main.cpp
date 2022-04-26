#include <iostream>
#include <SFML/Graphics.hpp>
#include "CrappyProgram.h"

int main() {
    srand(time(nullptr));
//    sf::err().rdbuf(nullptr);

    CrappyProgram crappyProgram;
    crappyProgram.run();

    return 0;
}
