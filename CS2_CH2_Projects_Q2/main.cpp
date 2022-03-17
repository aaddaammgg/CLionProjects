#include <iostream>

int main() {
    const double carpetPerMeter = 2.75, discountPercent = 0.15, discountMeter = 10;
    double carpetAmount, totalPrice;

    do {
        std::cout << "How much carpet in meters do you have?" << std::endl;
        std::cin >> carpetAmount;
    } while (carpetAmount <= 0);


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
