#include <iostream>
#include <ctime>

int main() {
    char repeat;
    int userInput, userGuess, cpuGuess, cpuGuessCount, min = 1, max = 1000;

    srand(time(0));

    do {
        std::cout << "Pick a number between " << min << " and " << max << ":" << std::endl;
        std::cin >> userInput;

        if (userInput < min || userInput > max) {
            std::cout << "Your input must be between " << min << " and " << max << ". Please try again." << std::endl;
            repeat = 'Y';
            continue;
        }

        cpuGuessCount = 0;

        while(true) {
            cpuGuess = rand() % (max + 1);
            cpuGuessCount++;

            if (cpuGuess == userInput) {
                break;
            }
        }

        std::cout << "Take a guess on how many attempts the CPU made to guess your number:" << std::endl;
        //std::cout << cpuGuessCount << std::endl; //debug

        while(true) {
            std::cin >> userGuess;

            if (userGuess == cpuGuessCount) {
                std::cout << "You guessed correctly! Congratulations!" << std::endl;
                break;
            } else if (userGuess > cpuGuessCount) {
                std::cout << "You guessed too high!" << std::endl;
            } else {
                std::cout << "You guessed too low!" << std::endl;
            }
        }

        std::cout << "Would you like to repeat? Y/N" << std::endl;
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
