#include<iostream>
using namespace std;

/**
 * PURPOSE: Returns the largest sum of any consecutive subarray using Kadane's Algorithm. (Wikipedia - Maximum subarray problem)
 * PARAMETERS: arr[] - Array of integers
 *             length - Size of array
 * RETURN VALUES: Largest consecutive subarray sum.
 */
int getLargestConsecutiveSum(const int arr[], int length) {
    int currentSum = 0;
    int maxSum = 0;

    for (int i = 0; i < length; ++i) {
        currentSum += arr[i];

        if (currentSum < 0) {
            currentSum = 0;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    // Your code will be tested with random input. For example:
    int int_array[] = {1, -3, 23, 4, 9, 2, 29, -3, 0, 2, 48, 7, 6, -1};
    cout << "Largest Consecutive Sum: " << getLargestConsecutiveSum(int_array, sizeof(int_array)/sizeof(*int_array));
    return 0;
}