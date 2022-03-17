#include <iostream>
#include <cmath>

void input(double &meters, double &cm);
void calcMC2FI(double meters, double cm, double &feet, double &inches);
void output(double feet, double inches);

int main() {
    double meters, cm, feet, inches;
    char repeat;

    do {
        std::cout << "This program will convert meters and centimeters to feet and inches\n";

        input(meters, cm);
        calcMC2FI(meters, cm, feet, inches);
        output(feet, inches);

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    return 0;
}

void input(double &meters, double &cm) {
    std::cout << "Meters:\n";
    std::cin >> meters;
    std::cout << "Centimeters:\n";
    std::cin >> cm;
}

void calcMC2FI(double meters, double cm, double &feet, double &inches) {
    double i = ((100 * meters) / 2.54) + (cm / 2.54);
    feet = floor(i/12);
    inches = i - (12 * feet);
}

void output(double feet, double inches) {
    std::cout << "The conversion is:\n" << feet << "ft " << inches << "in\n\n";
}