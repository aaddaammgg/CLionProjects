#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: Simulates ++N by representing its digits in a vector representation.
 * PARAMETERS: digits - a vector<int> each index representing the digit.
 * RETURN VALUES: Result of ++N in its vector form.
 */
vector<int> plusPlusN(vector<int> digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;

            return digits;
        }

        // We needed to carry
        digits[i] = 0;
    }

    // Push 1 at the beginning if it was a carry
    digits.insert(digits.begin(), 1);

    return digits;
}

int main() {
    // your target function will be tested like so, with random input
    vector<int> v {9};
    vector <int> retVal = plusPlusN(v); // retVal = [1,0]
    // etc.
    return 0;
}