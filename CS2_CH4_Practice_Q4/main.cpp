#include<iostream>

double inflationCalculation(double previousCost, double currentCost);

int main() {
    double previousCost, currentCost, rate;
    char repeat;

    do {
        std::cout << "Enter previous year cost of the item:\n";
        std::cin >> previousCost;
        std::cout << "Enter present year cost of the item:\n";
        std::cin >> currentCost;

        rate = inflationCalculation(previousCost, currentCost);

        std::cout << "Inflation rate: " << rate * 100 << "%\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

double inflationCalculation(double previousCost,double currentCost) {
    return (currentCost - previousCost) / currentCost;
}