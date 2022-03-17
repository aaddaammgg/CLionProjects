#include <iostream>

double hat(double weight, double height);
double jacket(double weight, double height, int age);
double waist(double weight, double height, int age);

int main() {
    double height, weight;
    int age;

    char repeat;

    do {
        std::cout << "Height (in inches):\n";
        std::cin >> height;

        std::cout << "Weight (in pounds):\n";
        std::cin >> weight;

        std::cout << "Age (in years):\n";
        std::cin >> age;

        std::cout << "Your hat size is: " << hat(weight, height) << "\n";
        std::cout << "Your jacket size is: " << jacket(weight, height, age) << "\n";
        std::cout << "Your waist size is: " << waist(weight, height, age) << "\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

double hat(double weight, double height) {
    return (weight / height) * 2.9;
}

double jacket(double weight, double height, int age) {
    double val = weight * height / 288;

    if (age >= 30) {
        val += (age / 8.0) * .125;
    }

    return val;
}

double waist(double weight, double height, int age) {
    double val = weight / 5.7;
    if (age > 28) {
        val += ((age - 28) / 2.0) * .1;
    }

    return val;
}