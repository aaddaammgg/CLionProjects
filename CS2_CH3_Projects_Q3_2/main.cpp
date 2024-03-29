#include <iostream>

enum Roman {
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000,

    INVALID = -1
};

int main() {
    std::string s;

    std::cout << "Convert from Roman to Integer:" << std::endl;
    std::cin >> s;

    int sum = 0;

    Roman last = INVALID; // Used to keep track of the last value

    for (int i = 0; i < s.length(); i++) {
        Roman current;

        switch (s[i]) {
            case 'I':
                current = I;
                break;
            case 'V':
                current =  V;
                break;
            case 'X':
                current =  X;
                break;
            case 'L':
                current =  L;
                break;
            case 'C':
                current =  C;
                break;
            case 'D':
                current =  D;
                break;
            case 'M':
                current =  M;
                break;
            default:
                current =  INVALID;
        }

        // if the last number was less than the current number
        // also, instead of using "INVALID" we can make use of i == 0 for first iteration
        if (last != INVALID && last < current) {
            sum -= last * 2; // two times the last because we want to subtract
        }

        sum += current;
        last = current;
    }

    std::cout << sum;

    return 0;
}
