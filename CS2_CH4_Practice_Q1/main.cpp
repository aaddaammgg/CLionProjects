#include <iostream>

double const LITER = 0.264172;
double milesPerGallon(int ml, int lt);

int main () {
	char repeat;
	int gasL, miles;
	do {
        std::cout << "Enter the number of Liters of gasoline:\n";
        std::cin >> gasL;
        std::cout << "Enter the number of miles traveled by the car:\n";
        std::cin >> miles;
        std::cout << "MPG: " << milesPerGallon(miles, gasL) << "\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');

	return 0;
}
double milesPerGallon(int m, int l) {
	double gallons;
	gallons = LITER * l;

	return (m / gallons);
}