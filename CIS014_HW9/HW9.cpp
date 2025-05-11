#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
    int getMaxPoints(vector<vector<int>> &maze);
};

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with a method called getMaxPoints(...) you will
// implement
// ------------------------------------------------------------

/**
 * PURPOSE: Finds the maximum points from top to bottom
 * PARAMETERS: maze - 2D vector of integers representing the maze.
 * RETURN VALUES: Maximum score possible
 */
int CIS14::getMaxPoints(vector<vector<int>> &maze) {
    if (maze.empty()) {
        return 0;
    }

    vector<int> max_score = maze[0];

    for (int row = 1; row < maze.size(); row++) {
        vector<int> nextRow(maze[row].size());

        for (int col = 0; col < maze[row].size(); col++) {
            int val = maze[row][col];

            if (col == 0) {
                nextRow[col] = max_score[col] + val;
            } else if (col == maze[row].size() - 1) {
                nextRow[col] = max_score[col - 1] + val;
            } else {
                int left = max_score[col - 1];
                int right = max_score[col];

                if (left > right) {
                    nextRow[col] = left + val;
                } else {
                    nextRow[col] = right + val;
                }
            }
        }

        max_score = nextRow;
    }

    int maxPoints = max_score[0];
    for (int i = 1; i < max_score.size(); i++) {
        if (max_score[i] > maxPoints) {
            maxPoints = max_score[i];
        }
    }

    return maxPoints;
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Your target method will be tested as such, with random input
    // as the following example illustrates
    vector<vector<int>> maze = {{0}, {4,1}, {5,3,8}, {1,6,7,3}};
    cout << cis14.getMaxPoints(maze) << endl; // 16

    return 0;
}