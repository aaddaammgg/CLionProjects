#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: Determines whether, with a given planted field (represented by the input integer array consisting 1s and 0s), you can plant n number of avocado seeds in it.
 * PARAMETERS: field - vector representing the field (0 = empty, 1 = planted)
 *             n - number of seeds to plant
 * RETURN VALUES: true if n seeds can be planted, false otherwise
 */
bool canPlantAvocados(vector<int> field, int n) {
    int size = field.size();

    for (int i = 0; i < size; i++) {
        if (field[i] == 0) {
            bool left = (i == 0) || (field[i - 1] == 0);
            bool right = (i == size - 1) || (field[i + 1] == 0);

            if (left && right) {
                field[i] = 1;
                n--;

                if (n <= 0) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    // your target function will be tested as such,
    // with random input
    vector<int> field = {1,0,1};
    cout << canPlantAvocados(field, 1); // function returns a boolean false,
    // which is 0 in cout
    return 0;
}
