//
// Created by Adam G. on 2/27/2022.
//

#include "AsterisksPattern.h"

AsterisksPattern::AsterisksPattern() : AsterisksPattern(8) {

}

AsterisksPattern::AsterisksPattern(int n) {
    patternRecursion(0, n);
}

void AsterisksPattern::patternRecursion(int j, int k) {
    if (k == 0) {
        return;
    }

    patternRecursion(j, k / 2);

    for (int i = 0; i < j; i++) {
        std::cout << " ";
    }
    for (int i = 0; i < k; i++) {
        std::cout << "*";
    }

    std::cout << std::endl;
    patternRecursion(j + (k / 2), k / 2);
}
