#include <iostream>
#include <cmath>

int main() {
    char repeat;
    double a, b, c, discriminant, x1, x2, real, imaginary;

    do {
        std::cout << "Enter the value of a:" << std::endl;
        std::cin >> a;

        if (a == 0) {
            std::cout << "Value 'a' cannot be 0. Please try again." << std::endl;
            repeat = 'Y';
            continue;
        }

        std::cout << "Enter the value of b:" << std::endl;
        std::cin >> b;

        std::cout << "Enter the value of c:" << std::endl;
        std::cin >> c;

        discriminant = (b * b) - (4 * a * c);


        if (discriminant == 0) {
            x1 = -b / (2 * a);
            std::cout << "One real root: " << std::endl;
            std::cout << "x1: " << x1 << std::endl;
        } else if (discriminant > 0) {
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "Two real roots:" << std::endl;
            std::cout << "x1: " << x1 << std::endl;
            std::cout << "x2: " << x2 << std::endl;
        } else {
            real = -b / (2 * a);
            imaginary = sqrt(-discriminant) / (2 * a);
            std::cout << "Two complex roots:" << std::endl;
            std::cout << "x1: " << real << "+" << imaginary << "i" << std::endl;
            std::cout << "x2: " << real << "-" << imaginary << "i" << std::endl;
        }

        std::cout << "Would you like to repeat? Y/N" << std::endl;
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
