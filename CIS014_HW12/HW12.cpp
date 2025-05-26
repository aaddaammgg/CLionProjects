#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class CIS14
{
public:
    int getSignal(vector<int> &);
};
// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with its method and the Node class you will use.
// <climits> is included to accommodate use of INT_MAX and/or INT_MIN.
// ------------------------------------------------------------

/**
 * PURPOSE: To check if the product of all numbers is positive, negative, or zero
 * PARAMETERS: ints - vector of integers
 * RETURN VALUE:
 *   -1 if the product is positive
 *    1 if the product is negative
 *    0 if the product is zero
*/
int CIS14::getSignal(vector<int> &ints)
{
    bool hasZero = false;
    int negativeCount = 0;

    for (int num : ints) {
        if (num == 0) {
            hasZero = true;
            break;
        }

        if (num < 0) {
            negativeCount++;
        }
    }

    if (hasZero) {
        return 0;
    }

    if (negativeCount % 2 == 0) {
        return -1;
    }

    return 1;
}


int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Your target method will be tested with random input such
    // as the following examples; the actual test cases will vary
    vector<int> v = {1, -1};
    cout << cis14.getSignal(v) << endl; // expects 1
    v = {1, 0, 1, 232, -23, 8, 109};
    cout << cis14.getSignal(v) << endl; // expects 0
    // etc.

    return 0;
}