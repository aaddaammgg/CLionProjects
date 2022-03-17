#include <iostream>
#include <iomanip>

int main() {
    const double rateDay = 0.40, rateNight = 0.25, rateWeekend = 0.15;
    double billingRate, totalPrice;
    char repeat;
    char day1, day2;
    char colon;
    int hour, minute, timeStarted, lengthCall;

    do {
        std::cout << "Enter the day of week (EX: MO TU WE TH FR SA SU):" << std::endl;
        std::cin >> day1 >> day2;

        day1 = toupper(day1);
        day2 = toupper(day2);

        std::cout << "Enter the time the phone call started (EX: 13:30):" << std::endl;
        std::cin >> hour >> colon >> minute;

        timeStarted = hour * 100 + minute;

        std::cout << "Enter the length of the call in minutes (EX: 15)" << std::endl;
        std::cin >> lengthCall;

        if ((day1 == 'S' && day2 == 'A') || (day1 == 'S' && day2 == 'U')) {
            billingRate = rateWeekend;
        } else if (timeStarted >= 800 && timeStarted <= 1800) {
            billingRate = rateDay;
        } else {
            billingRate = rateNight;
        }

        totalPrice = lengthCall * billingRate;

        std::cout << "The total price of the call is $" << std::setprecision(2) << std::fixed << totalPrice << std::endl;

        std::cout << "Would you like to repeat? Y/N" << std::endl;
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
