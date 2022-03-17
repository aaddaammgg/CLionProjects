#include <iostream>

int main() {
    double dueCost, dueInterest, minPayment, balance;
    const double interest = .015;
    const double overInterest = .01;
    char repeat;
    do {
        std::cout << "Enter account balance:\n";
        std::cin >> balance;

        if (balance > 1000) {
            dueInterest = (balance - 1000) * overInterest;
            dueInterest += 1000 * interest
        } else {
            dueInterest = balance * interest;
        }
        dueCost = balance + dueInterest;

        if (dueCost * .1 > 10) {
            minPayment = dueCost * .1;
        } else {
            minPayment = 10;
        }

        std::cout << "\nInterest due: " << dueInterest;
        std::cout << "\nTotal amount due: " << dueCost;
        std::cout << "\nMinimum payment: " << minPayment;

        std::cout << "\nWould you like to repeat? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    return 0;
}
