#include <iostream>

int main() {
    double carpetAmount, totalPrice, carpetPerMeter, discountPercent, discountMeter;

    do {
        std::cout << "Enter the price of carpet per meter:" << std::endl;
        std::cin >> carpetPerMeter;

        std::cout << "Enter the discount percent:" << std::endl;
        std::cin >> discountPercent;

        std::cout << "Enter the minimum length of carpet that is applicable for the discount:" << std::endl;
        std::cin >> discountMeter;

        std::cout << "How much carpet in meters do you have?" << std::endl;
        std::cin >> carpetAmount;
    } while (carpetAmount <= 0 || carpetPerMeter <= 0 || discountPercent <= 0 || discountMeter <= 0);

    if (discountPercent > 1) {
        discountPercent /= 100;
    }

    if (carpetAmount > discountMeter) {
        carpetAmount -= discountMeter;
        totalPrice = carpetAmount * (carpetPerMeter - (carpetPerMeter * discountPercent) );
        totalPrice += discountMeter * carpetPerMeter;
    } else {
        totalPrice = carpetAmount * carpetPerMeter;
    }

    std::cout << "Your total price is: $" << totalPrice;
    return 0;
}
