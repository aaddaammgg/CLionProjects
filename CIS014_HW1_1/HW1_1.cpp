/**
* PURPOSE: this console program breaks the total number of pennies into
*          respective USD and CAN denominations, and print the string buffer
*          containing the entire formatted output string to the console display
* PARAMETERS:
*     	None
* RETURN VALUES:
*     	None
*/

#include <iostream>

int main() {

    int numPennies = 0;
    std::cout << "Please enter all of your pennies: " << std::endl;
    std::cin >> numPennies;

    if (numPennies < 0) {
        std::cout << "Invalid input.";

        return 0;
    }

    int dollars, quarters, dimes, nickels;

    const double exchangeRate = 1.33;
    const double canDollars = (numPennies / 100.00) * exchangeRate;

    dollars = numPennies / 100;
    numPennies = numPennies - dollars * 100;
    quarters = numPennies / 25;
    numPennies = numPennies - quarters * 25;
    dimes = numPennies / 10;
    numPennies = numPennies - dimes * 10;
    nickels = numPennies / 5;
    numPennies = numPennies - nickels * 5;

    std::cout << "In US currency you have: "
                << dollars << " dollars, "
                << quarters << " quarters, "
                << dimes << " dimes, "
                << nickels << " nickels, and "
                << numPennies << " pennies." << std::endl;

    std::cout << "In Canadian currency you have: "
                << canDollars << " dollars." << std::endl;

    return 0;
}