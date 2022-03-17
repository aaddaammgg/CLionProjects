#include <iostream>
#include "time.h"

void round(bool shooter, bool &target1, bool &target2, double accuracy);
void shoot(bool &targetAlive, double accuracy);
double getAccuracy();
char startDuel();
void calculateScore();
double probability(int wins, int trials);
void puzzlevania();

int main() {
    srand(time(0));

    puzzlevania();

    return 0;
}

void driver() {
    char repeat;
    double accuracy;

    do {
        bool target = true;
        std::cout << "Enter an accuracy:\n";
        std::cin >> accuracy;
        shoot(target, accuracy);
        if (target) {
            std::cout << "You are still alive!\n";
        } else {
            std::cout << "You are dead\n";
        }
        std::cout << "Would you like to run this program again? Y/N\n";
        std::cin >> repeat;
    } while(repeat == 'Y' || repeat == 'y');
}

void shoot(bool &targetAlive, double accuracy) {
    double shot = getAccuracy();
    if (shot < accuracy) {
        targetAlive = false;
    }
}

double getAccuracy() {
    return rand() % 100 / 100.0;
}

char startDuel() {
    bool aaron = true, bob = true, charlie = true;

    while ((aaron && bob) || (aaron && charlie) || (charlie && bob)) {
        round(aaron, charlie, bob, 0.33);
        round(bob, charlie, aaron, 0.5);
        round(charlie, bob, aaron, 1);
    }

    if (aaron) {
        return 'a';
    } else if (bob) {
        return 'b';
    } else if (charlie) {
        return 'c';
    } else {
        return 'e';
    }
}

void round(bool shooter, bool &target1, bool &target2, double accuracy) {
    if (shooter) {
        if (target1) {
            shoot(target1, accuracy);
        } else {
            shoot(target2, accuracy);
        }
    }
}

void calculateScore() {
    int aaronWins = 0, bobWins = 0, charlieWins = 0;

    for (int i = 0; i < 1000; i++) {
        switch (startDuel()) {
            case 'a':
                aaronWins++;
                break;
            case 'b':
                bobWins++;
                break;
            case 'c':
                charlieWins++;
                break;
        }
    }
    std::cout << "Aaron's probability: " << probability(aaronWins, 1000) << "\n";
    std::cout << "Bob's probability: " << probability(bobWins, 1000) << "\n";
    std::cout << "Charlie's probability: " << probability(charlieWins, 1000) << "\n";
}

double probability(int wins, int trials) {
    return wins / static_cast<double>(trials) * 100;
}

void puzzlevania() {
    calculateScore();
}