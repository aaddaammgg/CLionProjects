#include <iostream>

int main() {
    double metricTonInOunces = 35273.92, cerealInOunces;
    char repeat;

    std::cout << "Input the weight of breakfast cereal in ounces:" << std::endl;
    std::cin >> cerealInOunces;

    std::cout << cerealInOunces << " Ounces is " << cerealInOunces/metricTonInOunces << " Metric Tons" << std::endl;
    std::cout << "The number of boxes of cereal that can yield to one ton is " << metricTonInOunces/cerealInOunces << std::endl;

    std::cout << std::endl << "Would you like to repeat this program? Y/N" << std::endl;
    std::cin >> repeat;

    if (repeat == 'Y' || repeat == 'y') {
        std::cout << std::endl << std::endl;
        main();
    }

    return 0;
}
