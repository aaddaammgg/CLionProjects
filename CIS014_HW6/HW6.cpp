#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* PURPOSE: Splits a string into a list of integers.
* PARAMETERS: str: input string, delim: separator character.
* RETURN VALUES: Vector of integers from the split string.
*/
vector<int> splitByChar(const string& str, const char delim) {
    vector<int> result;
    int num = 0;
    bool hasNum = false;

    for (int i = 0; i <= str.size(); i++) {
        if (i < str.size() && isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
            hasNum = true;
        } else if (i == str.size() || str[i] == delim) {
            result.push_back(hasNum ? num : 0);
            num = 0;
            hasNum = false;
        }
    }

    return result;
}

/**
* PURPOSE: Compares two software version strings.
* PARAMETERS: ver1, ver2: version strings separated by dots.
* RETURN VALUES: 1 if ver1 > ver2, -1 if ver1 < ver2, 0 if equal.
*/
int compareVersions(string ver1, string ver2) {
    vector<int> v1 = splitByChar(ver1, '.');
    vector<int> v2 = splitByChar(ver2, '.');

    int size = v1.size() > v2.size() ? v1.size() : v2.size();

    for (int i = 0; i < size; i++) {
        int num1 = i < v1.size() ? v1[i] : 0;
        int num2 = i < v2.size() ? v2[i] : 0;

        if (num1 > num2) {
            return 1;
        }

        if (num1 < num2) {
            return -1;
        }
    }
    return 0;
}

int main() {
    // your target function will be tested as such, with
    // random input. To streamline your testing, you may
    // also test your own code this way:
    // cout << (compareVersions("0.1", "0.1") == 0); // 1, which is true
    cout << compareVersions("0.1", "0.1"); // 0
    return 0;
}