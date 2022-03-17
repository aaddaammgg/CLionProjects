#include <iostream>

double stockCalculate(int whole, int numerator, int denominator, int stockAmount);

int main() {
    int whole, numerator, denominator, stockAmount;
    double value;
    char repeat;

    do {
        std::cout << "Enter number of shares:\n";
        std::cin >> stockAmount;
        std::cout << "Enter whole-dollar portion of the price:\n";
        std::cin >> whole;
        std::cout << "Enter numerator:\n";
        std::cin >> numerator;
        std::cout << "Enter denominator:\n";
        std::cin >> denominator;

        value = stockCalculate(whole, numerator, denominator, stockAmount);

        std::cout<<"Cost of single stock: " << value << "\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

double stockCalculate(int whole, int numerator, int denominator, int stockAmount) {
    return (double)(whole * denominator + numerator)/(denominator * stockAmount);
}