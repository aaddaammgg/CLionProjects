#include <iostream>
#include <iomanip>
#include <cmath>

long double func(long double x);

int main() {
    const long double from = 0;
    const long double to = 2 * M_PI;

    int n;

    std::cout << "Enter n: " << std::endl;
    std::cin >> n;

    const long double delta_x = (to - from) / n;

    long double starting = delta_x / 2;
    long double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += func(starting);
        starting += delta_x;
    }

    std::cout << std::setprecision(5);

    std::cout << "\nMidpoint Riemann Sum\n";
    std::cout << '(' << from << ", " << to << ")\n";
    std::cout << "n: " << n << '\n';
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "∆x: " << delta_x << '\n';
    std::cout << std::setprecision(5);
    std::cout << "Sum of the area of " << n << " segments: " << sum << "\n\n";

    std::cout << std::setprecision(50);

    std::cout << "∆x * Sum (50 decimal places): " << delta_x * sum << '\n';

    return 0;
}

long double func(long double x) {
    return std::sqrt(1 + std::pow(std::cos(x), 2));
}
