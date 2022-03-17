#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, x1, x2;

    cout << "Enter the values for a, b, c: ";
    cin >> a >> b >> c;

    x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
    x2 = (-b - sqrt(b*b - 4*a*c)) / 2*a;

    cout << endl << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;

    return 0;
}
