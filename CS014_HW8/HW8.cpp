#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: Will suggest the maximum profit an investor can make by placing AS MANY
 *          buy-sell orders as you may in the given time slice your input vector represents.
 * PARAMETERS: prices - Pass by reference vector of integers
 * RETURN VALUES: The total profit.
 */
int getMaxProfit(vector<int>& prices) {
    int n = prices.size();
    int profit = 0;

    for (int i = 1; i < n; i++) {
        int curr = prices[i];
        int prev = prices[i - 1];

        if (curr > prev) {
            profit += curr - prev;
        }
    }

    return profit;
}
int main() {
    // your target function will be tested as such, with random input like so
    vector<int> arr{1, 2, 4};
    cout << getMaxProfit(arr); // 3
    return 0;
}