#include <iostream>

void input24HR(int &hours, int &min);
void convertTo12HR(int &hours, char &type);
void display12HR(int hours, int min, char type);

int main() {
    int hours, min;
    char type, repeat;
    do {
        std::cout << "Please enter the time in 24 hour notation to convert to 12 hour notation.\n";
        input24HR(hours, min);
        convertTo12HR(hours, type);
        display12HR(hours, min, type);
        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while(repeat == 'Y' || repeat == 'y');

    return 0;
}

void input24HR(int &hours, int &min) {
    std::cout << "Hours:\n";
    std::cin >> hours;
    std::cout << "Minutes:\n";
    std::cin >> min;
}

void convertTo12HR(int &hours, char &type) {
    if (hours > 12) {
        hours %= 12;
        type = 'P';
    } else {
        type = 'A';
    }
}

void display12HR(int hours, int min, char type) {
    std::cout << "The 12 hour conversion is: " << hours << ":" << min << " " << type << ".M.\n\n";
}