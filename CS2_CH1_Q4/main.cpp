#include <iostream>
using namespace std;
int main() {
    int firstNum, secondNum, totalNum;
    cout << "Press return after entering a number.\n";
    cout << "What is the first number you would like to subtract:\n";
    cin >> firstNum;
    cout << "What is the second number you would like to subtract:\n";
    cin >> secondNum;
    totalNum = firstNum - secondNum;
    cout << "The difference of ";
    cout << firstNum;
    cout << " and ";
    cout << secondNum;
    cout << " is ";
    cout << totalNum;
    return 0;
}
