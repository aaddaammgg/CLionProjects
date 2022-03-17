#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, x1, y1, x2, y2;

    cout << "Enter the first point: ";
    cin >> x1 >> y1;

    cout << endl << "Enter the second point: ";
    cin >> x2 >> y2;

    x = (x1 + x2) / 2;
    y = (y1 + y2) / 2;

    cout << endl << "Midpoint: (" << x << ", " << y << ")" << endl;

    return 0;
}
