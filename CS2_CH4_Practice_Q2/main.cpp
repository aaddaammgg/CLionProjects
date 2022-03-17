#include <iostream>

double const LITER = 0.264172;
double milesPerGallon(int ml, int lt);
double outputInfo(double car[], int size, std::string order);

enum {GAS = 0, MILES, MPG};

int main () {
    char repeat;
    int size = 3;
    double car1[size];
    double car2[size];
    std::string bestMPG;

    do {
        outputInfo(car1, size, "first");
        outputInfo(car2, size, "second");

        if (car1[MPG] > car2[MPG]) {
            bestMPG = "first";
        } else {
            bestMPG = "second";
        }

        std::cout << "The " << bestMPG << " car has the best fuel efficiency.\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

double outputInfo(double car[], int size, std::string order) {
    std::cout << "Enter the number of Liters of gasoline for the " << order << " car:\n";
    std::cin >> car[GAS];
    std::cout << "Enter the number of miles traveled for the " << order << " car:\n";
    std::cin >> car[MILES];

    car[MPG] = milesPerGallon(car[GAS], car[MILES]);

    order[0] = toupper(order[0]);
    std::cout << order << " car MPG: " << car[MPG] << "\n\n";
}

double milesPerGallon(int m, int l) {
    double gallons;
    gallons = LITER * l;

    return (m / gallons);
}