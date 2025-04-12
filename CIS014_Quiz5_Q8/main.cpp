// importing the necessary libraries
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
using namespace std;

int main() {
    // declare a 10x10 array for a multiplication table
    const int nNumRows = 10;
    const int nNumCols = 10;
    int nProducts[nNumRows][nNumCols] = {0};
    cout << setw(5);

    // calculate multiplication table
    for (int nRow=1; nRow<nNumRows; nRow++)
        for (int nCol=1; nCol<nNumCols; nCol++)
            nProducts[nRow][nCol] = nRow * nCol;

    // print the table
    for (int nRow=1; nRow<nNumRows; nRow++) {
        for (int nCol=nRow; nCol<nNumCols; nCol++)
            cout << nProducts[nRow][nCol] << setw(5);
        cout << endl;
    }

    return 0;
}