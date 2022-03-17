#include <iostream>

std::string getWinningPhrase(int ply1, int ply2);
std::string getWinner(int ply1, int ply2);
int char2INT(char choice);

enum {ROCK = 0, PAPER, SCISSOR};
enum {DRAW = 0, PLY1, PLY2};

int main() {
    char repeat;
    char plyChar1, plyChar2;
    int ply1, ply2;

    do {
        std::cout << "What was the first player's choice? (R/P/S) \n";
        std::cin >> plyChar1;
        std::cout << "What was the second player's choice? (R/P/S) \n";
        std::cin >> plyChar2;

        ply1 = char2INT(plyChar1);
        ply2 = char2INT(plyChar2);

        std::string winnerMsg = getWinningPhrase(ply1, ply2);

        std::cout << winnerMsg << "\n";

        std::cout << "Would you like to repeat? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

int char2INT(char choice) {
    switch(choice) {
        case 'R':
        case 'r':
            return ROCK;
        case 'P':
        case 'p':
            return PAPER;
        case 'S':
        case 's':
            return SCISSOR;
        default:
            return NULL;
    }
}

std::string getWinner(int ply1, int ply2) {
    int chooseWinner[3][3] = {{0, 2, 1}, // 2D Arrays :)
                        {1, 0, 2},
                        {2, 1, 0}};

    int winner = chooseWinner[ply1][ply2];

    switch(winner) {
        case DRAW:
            return "Draw!";
        case PLY1:
            return "Player one wins!";
        case PLY2:
            return "Player two wins!";
        default:
            return "ERROR";
    }
}

std::string getWinningPhrase(int ply1, int ply2) {
    std::string winningPhrase;
    winningPhrase = getWinner(ply1, ply2) + " ";

    if (ply1 != ply2) {
        if (ply1 + ply2 == 1) {
            winningPhrase += "Paper covers rock.";
        } else if (ply1 + ply2 == 2) {
            winningPhrase += "Rock breaks scissors.";
        } else if (ply1 + ply2 == 3) {
            winningPhrase += "Scissors cut paper.";
        }
    } else {
        winningPhrase += "Nobody wins.";
    }

    return winningPhrase;
}