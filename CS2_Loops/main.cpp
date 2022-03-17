#include <iostream>

int main() {
    char letter;
    bool playAgain;
    std::cout << time;
    do {
        std::cout << "Do you want to play again?" << std::endl;
        std::cin >> letter;

        switch(letter) {
            case 'y':
            case 'Y':
                playAgain = true;
                break;
            default:
                playAgain = false;
        }
    } while(playAgain);

    return 0;
}
