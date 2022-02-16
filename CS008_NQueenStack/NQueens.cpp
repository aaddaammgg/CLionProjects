//
// Created by Adam G. on 2/14/22.
//

#include "NQueens.h"

bool NQueens::isConflict() {
    std::stack<std::pair<int, int>> tempQueens;
    std::pair<int, int> origQueensTop = queens.top();

    tempQueens.push(origQueensTop);
    queens.pop();

    while (!queens.empty()) {
        if (origQueensTop.first == queens.top().first ||
            origQueensTop.second == queens.top().second ||
            (abs(origQueensTop.first - queens.top().first) ==
             abs(origQueensTop.second - queens.top().second))) {

            while(!tempQueens.empty()) {
                queens.push(tempQueens.top());
                tempQueens.pop();
            }

            return true;
        }
        tempQueens.push(queens.top());
        queens.pop();
    }

    while(!tempQueens.empty()) {
        queens.push(tempQueens.top());
        tempQueens.pop();
    }

    return false;
}

bool NQueens::isOutOfBounds() {
    return (queens.top().first > (_n - 1)) || (queens.top().second + 1 > (_n - 1));
}

void NQueens::solve(int n) {
    bool success = false;
    queens.push({0, 0});
    this->_n = n;
    initArray();

    while (!success && !queens.empty()) {

        if (isConflict()) {
            if (!isOutOfBounds()) {
                queens.top().second++;
            } else {
                while (!queens.empty() && isOutOfBounds()) {
                    queens.pop();
                    if (!queens.empty()) {
                        queens.top().second++;
                    }
                }
            }
        } else if (queens.size() == n) {
            success = true;
        } else {
            std::pair<int, int> newQueen = queens.top();

            newQueen.first++;
            newQueen.second = 0;

            queens.push(newQueen);
        }
    }

    std::cout << n << "x" << n << " is " << ((success) ? "" : "not ") << "solvable" << std::endl << std::endl;
}

void NQueens::initArray() {
    arr = new char*[_n];
    for (int i = 0; i < _n; i++) {
        arr[i] = new char[_n];
    }
}

void NQueens::print() {
    while (!queens.empty()) {
        arr[queens.top().first][queens.top().second] = 'Q';
        queens.pop();
    }

    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            std::cout << std::setw(2);
            if (arr[i][j] != 'Q') {
                std::cout << "X";
            } else {
                std::cout << arr[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
