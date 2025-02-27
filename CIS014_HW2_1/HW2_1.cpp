#include <iostream>

/**
 * PURPOSE: Pebbles winning strategy for first player
 * PARAMETER: n (the initial number of pebbles)
 * RETURN VALUE: true if the first player can force a win, false otherwise
 */
bool canAlwaysWin(int n) {
    return n % 8 != 0;
}
int main() {
    //Your target function will be tested as such, with a random integer argument:
    std::cout << canAlwaysWin(9);
    return 0;
}