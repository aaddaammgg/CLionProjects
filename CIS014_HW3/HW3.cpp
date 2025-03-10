#include <iostream>
using namespace std;

/**
 * PURPOSE: Rearranges a finite-length binary string ('a's and 'b's) so that all 'a' characters follow immediately after a 'b'.
 * PARAMETERS: A string containing only 'a' and 'b'.
 * RETURN VALUES: A new string with all 'b's followed by 'a's.
 */
string separateLetters(string input) {
    string result;

    int size = input.length();

    for (int i = 0; i < size; i++) {
        if (input[i] == 'b') {
            result += 'b';
        }
    }

    for (int i = 0; i < size; i++) {
        if (input[i] == 'a') {
            result += 'a';
        }
    }

    return result;
}

int main() {
    // Your target function will be tested as such,
    // with a random, hardcoded input
    // test case #1
    cout << separateLetters("a"); // return a
    // test case #2
    cout << separateLetters("abababa"); // return bbbaaaa
    // etc.


    string input = "test";

    cout << input[input.length() - 1] << endl;
    return 0;
}