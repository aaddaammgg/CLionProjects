#include <iostream>
#include <cmath>

void input(double &x, double &y, int &convertFrom);
void calcFI2MC(double feet, double inches, double &meters, double &cm);
void calcMC2FI(double meters, double cm, double &feet, double &inches);
void output(double a, double b, int convertFrom);
enum {FI = 1, MC};

int main() {
    double x, y, a, b;
    int convertFrom;
    char repeat;


    do {
        std::cout << "What would you like to convert from?\n(1) Feet and Inches\n(2) Meters and Centimeters\n";

        input(x, y, convertFrom);

        if (convertFrom == FI) {
            calcFI2MC(x, y, a, b);
        } else {
            calcMC2FI(x, y, a, b);
        }

        output(a, b, convertFrom);

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    return 0;
}

void input(double &x, double &y, int &convertFrom) {
    do {
        std::cout << "Choice:\n";
        std::cin >> convertFrom;
    } while (convertFrom < 1 || convertFrom > 2);


    if (convertFrom == FI) {
        std::cout << "Feet:\n";
        std::cin >> x;
        std::cout << "Inches:\n";
        std::cin >> y;
    } else {
        std::cout << "Meters:\n";
        std::cin >> x;
        std::cout << "Centimeters:\n";
        std::cin >> y;
    }
}

void calcFI2MC(double feet, double inches, double &meters, double &cm) {
    meters = feet * 0.3048 + (inches * 0.0254);
    int m = (int) meters;
    cm = (meters - (double) m) * 100;
    meters = m;
}

void calcMC2FI(double meters, double cm, double &feet, double &inches) {
    double i = ((100 * meters) / 2.54) + (cm / 2.54);
    feet = floor(i/12);
    inches = i - (12 * feet);
}

void output(double a, double b, int convertFrom) {
    std::cout << "The conversion is:\n" << a;

    if (convertFrom == FI) {
        std::cout << "m " << b << "cm";
    } else {
        std::cout << "ft " << b << "in";
    }

    std::cout << "\n\n";
}