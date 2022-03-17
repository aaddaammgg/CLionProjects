#include <iostream>

void input(double &feet, double &inches);
void calcFI2MC(double feet, double inches, double &meters, double &cm);
void output(double meters, double cm);

int main() {
    double feet, inches, meters, cm;
    char repeat;

    do {
        std::cout << "This program will convert feet and inches to meters and centimeters\n";

        input(feet, inches);
        calcFI2MC(feet,inches,meters,cm);
        output(meters, cm);

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    return 0;
}

void input(double &feet, double &inches) {
    std::cout << "Feet:\n";
    std::cin >> feet;
    std::cout << "Inches:\n";
    std::cin >> inches;
}

void calcFI2MC(double feet, double inches, double &meters, double &cm) {
    meters = feet * 0.3048 + (inches * 0.0254);
    int m = (int) meters;
    cm = (meters - (double) m) * 100;
    meters = m;
}

void output(double meters, double cm) {
    std::cout << "The conversion is:\n" << meters << "m " << cm << "cm\n\n";
}