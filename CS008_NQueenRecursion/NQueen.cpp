//
// Created by Adam G. on 2/16/22.
//

#include "NQueen.h"

NQueen::NQueen() : NQueen(4) {

}

NQueen::NQueen(int n) {
    queens = new int[n];
    sizeRowCol = n; // sizeRowCol is our placeholder

    std::cout << "Checking solutions for " << n << "x" << n << "..." << std::endl << std::endl;

    solveNQueens(1); // start at one not n

    if (solutions == 0) {
        std::cout << "No solutions for " << n << "x" << n;
    } else {
        std::cout << "Found " << solutions << " solutions for " << n << "x" << n;
    }

    std::cout << std::endl << std::endl;
}

NQueen::~NQueen() {
    delete [] queens;
}

bool NQueen::canPlace(int row, int col) {
    for (int iRow = 1; iRow <= (row - 1); iRow++) {
        if ((queens[iRow] == col) || (abs(queens[iRow] - col)) == (abs(iRow - row))) {
            return false;
        }
    }

    return true;
}

void NQueen::solveNQueens(int row) {
    for (int iCol = 1; iCol <= sizeRowCol; iCol++) {
        if (canPlace(row, iCol)) {
            queens[row] = iCol;
            if (row == sizeRowCol) { // solution found once we reach last row!
                solutions++;
                printSolution();
            } else {
                solveNQueens(row + 1); // increase row and call itself
            }
        }
    }
}

void NQueen::printSolution() {
    for (int i = 1; i <= sizeRowCol; i++) {
        for (int j = 1; j <= sizeRowCol; j++) {
            std::cout << std::setw(2);
            if (queens[i] == j) {
                std::cout << "Q";
            } else {
                std::cout << "X";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}
