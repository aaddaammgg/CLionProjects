//
// Created by Adam G. on 2/14/22.
//

#ifndef NQUEENSTACK_NQUEENS_H
#define NQUEENSTACK_NQUEENS_H

#include <stack>
#include <utility>
#include <cmath>
#include <iostream>
#include <iomanip>

class NQueens {
private:
    std::stack<std::pair<int, int>> queens;
    int _n;
    char** arr;
    bool isConflict();
    bool isOutOfBounds();
    void initArray();
public:
    void solve(int n);
    void print();
};


#endif //NQUEENSTACK_NQUEENS_H
