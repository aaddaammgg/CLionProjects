#include <iostream>

int main() {
    double faceValue, interestRate, loanPeriod;
    double calculatedLoanAmount, interestOwed, loanPeriodYear;
    char repeat;
    do {
        do {
            std::cout << "Enter the loan amount: " << std::endl;
            std::cin >> faceValue;

            std::cout << "Enter the interest rate: " << std::endl;
            std::cin >> interestRate;

            std::cout << "Enter the loan period in months: " << std::endl;
            std::cin >> loanPeriod;
        } while (faceValue <= 0 || interestRate <= 0 || loanPeriod <= 0);

        if (interestRate > 1) {
            interestRate /= 100;
        }

        loanPeriodYear = loanPeriod / 12;

        interestOwed = interestRate * loanPeriodYear;
        calculatedLoanAmount = faceValue / (1-interestOwed);

        std::cout << "To receive a face value of $" << faceValue << std::endl;
        std::cout << "You will need to take out a loan of $" << calculatedLoanAmount << " at " << interestRate * 100 << "%" << std::endl;
        std::cout << "Your monthly payments will be $" << calculatedLoanAmount / loanPeriod << std::endl;

        std::cout << "Would you like to repeat? Y/N" << std::endl;
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
