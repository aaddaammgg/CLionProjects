#include <iostream>

int main() {
    int numCards, numScore, numAces;
    char repeat, card;

    do {
        numScore = 0;
        numAces = 0;

        std::cout << "Enter the number of cards (2-5):" << std::endl;
        std::cin >> numCards;

        if (numCards < 2 || numCards > 5) {
            std::cout << "Invalid input. Please try again." << std::endl;
            repeat = 'Y';
            continue;
        }

        for (int i = numCards; i > 0; i--) {
            std::cout << "Enter the card value:" << std::endl;
            std::cin >> card;

            card = toupper(card);

            if (card >= '2' && card <= '9') {
                numScore  += (int)(card - '0');
            } else if (card == 'J' || card == 'T' || card == 'Q' || card == 'K') {
                numScore += 10;
            } else if (card == 'A') {
                numAces++;
            }
        }
        if (numAces > 0) {
            while (numAces > 1) {
                numScore += 1;
                numAces--;
            }

            if (numScore > 10) {
                numScore += 1;
            } else {
                numScore += 11;
            }
        }
        if (numScore > 21) {
            std::cout << "Busted!" << std::endl;
        } else {
            std::cout << "Score: " << numScore << std::endl;
        }

        std::cout << "Would you like to repeat? Y/N" << std::endl;
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
}