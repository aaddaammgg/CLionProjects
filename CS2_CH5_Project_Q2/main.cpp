#include <iostream>

int main() {
    int curHour, curMin, waitHour, waitMin, hour, min;
    char repeat;

    do {
        std::cout << "This program will calculate the current time plus the wait time.\n";
        std::cout << "Enter the current hour:\n";
        std::cin >> curHour;

        std::cout << "Enter the current minute:\n";
        std::cin >> curMin;

        std::cout << "Enter the number of hour(s) to wait:\n";
        std::cin >> waitHour;

        std::cout << "Enter the number of minute(s) to wait:\n";
        std::cin >> waitMin;

        hour = curHour + waitHour;
        min = curMin + waitMin;

        if (min >= 60) {
            int minToHour = min / 60;
            hour += minToHour;
            min -= minToHour * 60;
        }

        std::cout << "The time would be at " << hour << ":" << min << "\n\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');


    return 0;
}
