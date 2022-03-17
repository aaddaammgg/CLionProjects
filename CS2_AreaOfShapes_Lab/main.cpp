#include <iostream>

using namespace std;

int main() {
    double area, length, height, base, radius, pi = 3.143159;

    length = 3;
    height = 2;
    area = length * height;
    cout << "The area of the rectangle is " << area << endl;

    base = 5;
    height = 2;
    area = (base / 2) * height;
    cout << "The area of the triangle is " << area << endl;

    radius = 2;
    area = pi * (radius * radius);
    cout << "The area of the circle is " << area << endl;

    return 0;
}
