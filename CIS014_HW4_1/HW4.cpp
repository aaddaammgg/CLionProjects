#include <iostream>
#include <vector>
using namespace std;

// API DOCUMENTATION BELOW. PLEASE FILL THE FOLLOWING API PRIOR TO CODING
/**
 * PURPOSE: Returns a vector of "Champion Numbers" within a given range.
 *          A "Champion Number" is a number that is divisible by every one of its digits.
 * PARAMETER:
 *   begin: Start of range (inclusive)
 *   end: End of range (inclusive)
 * RETURN VALUE: A vector containing all "Champion Numbers" within the given range.
 */
vector<int> getChampions(int begin, int end) {
    vector<int> champions;

    for (int num = begin; num <= end; num++) {
        string numStr = to_string(num);
        bool isChampion = true;

        for (char digitChar : numStr) {
            int digit = digitChar - '0';

            if (digit == 0 || num % digit != 0) {
                isChampion = false;
                break;
            }
        }

        if (isChampion) {
            champions.push_back(num);
        }
    }

    return champions;
}

int main() {
    // your target function will be tested as such,
    // with a random begin and end value such as:
    vector<int> a = getChampions(1, 22);

    // this is one example to print out your vector content
    // in the ascending order
    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    return 0;
}