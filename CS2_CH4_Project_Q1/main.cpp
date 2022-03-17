#include <iostream>

double annualCost(double initialLoanBalance);
double taxSavings(double initialLoanBalance);
double initialLoanBalance(double housePrice, double downPayment);

int main() {
    double housePrice, downPayment, initialBalance, afterTax;
    char repeat;

    do
    {
        std::cout << "House price:\n";
        std::cin >> housePrice;

        std::cout << "Down payment:\n";
        std::cin >> downPayment;

        initialBalance = initialLoanBalance(housePrice, downPayment);
        afterTax = annualCost(initialBalance) - taxSavings (initialBalance);

        std::cout << "Your annual after-tax cost is $" << afterTax << "\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

double annualCost(double initialLoanBalance) {
    return initialLoanBalance * .09;
}

double taxSavings (double initialLoanBalance) {
    return initialLoanBalance * .021;
}

double initialLoanBalance(double housePrice, double downPayment) {
    return housePrice - downPayment;
}