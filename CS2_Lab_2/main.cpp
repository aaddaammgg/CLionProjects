#include <iostream>

double areaOfTriangle(double base, double height);

int main() {
    double area = areaOfTriangle(6,7);
    std::cout << "Area: " << area << std::endl;
    return 0;
}

double areaOfTriangle(double base, double height) {
    return (0.5 * base) * height;
}