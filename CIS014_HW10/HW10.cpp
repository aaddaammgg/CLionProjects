#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
    vector<int> getMaxHits(vector<int> &requests, int window_size);
};

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with its method you will implement.
// ------------------------------------------------------------

/**
 * PURPOSE: Compute the maximum value in each rolling window of a given size
 * PARAMETERS:
 *     - requests: vector of integers of counts
 *     - window_size: size of the sliding window
 * RETURN VALUES: A vector of integers representing the max in each rolling window
 */
vector<int> CIS14::getMaxHits(vector<int> &requests, int window_size) {
    vector<int> result;

    if (window_size == 0 || window_size > requests.size()) {
        return result;
    }

    for (int i = 0; i <= requests.size() - window_size; i++) {
        int max = requests[i];

        for (int j = 1; j < window_size; j++) {
            if (requests[i + j] > max) {
                max = requests[i + j];
            }
        }

        result.push_back(max);
    }

    return result;
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Your target method will be tested with random input such
    // as the following example; the actual test cases will vary
    vector<int> v = {1,2,4};
    vector<int> ans = cis14.getMaxHits(v,1);

    // You may use the following code to print out your returned vector's content
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");

    return 0;
}

