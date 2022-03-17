#include <iostream>

int main() {
    double milesPerHour, minute, seconds;
    int minuteWhole;

    std::cout << "Input the MPH to convert it to minute per mile:" << std::endl;
    std::cin >> milesPerHour;

    minute = 60 / milesPerHour;
    minuteWhole = static_cast<int>(minute);
    seconds = (minute - minuteWhole) * 60;

    std::cout << milesPerHour << " mph is " << minuteWhole << " minute(s) " << seconds << " second(s) per mile";

    return 0;
}
