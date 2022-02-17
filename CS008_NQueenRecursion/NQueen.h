//
// Created by Adam G. on 2/16/22.
//

#ifndef CS008_NQUEENRECURSION_NQUEEN_H
#define CS008_NQUEENRECURSION_NQUEEN_H

#include <iostream>
#include <cmath>
#include <iomanip>

class NQueen {
private:
    int* queens;
    int sizeRowCol;
    int solutions = 0;

    bool canPlace(int row, int col);
    void printSolution();
    void solveNQueens(int row);
public:
    NQueen();
    NQueen(int n);
    ~NQueen();

};


#endif //CS008_NQUEENRECURSION_NQUEEN_H
