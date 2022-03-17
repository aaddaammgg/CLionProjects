#include <iostream>

int main() {
    const double percSweetenerSoda = 0.001, gramsSoda = 350.0;
    double gramsSweetener, gramsMouse, gramsDieter, amtOfSoda;
    char repeat;

    do {
        repeat = 'n';
        std::cout << "What is the amount of artificial sweetener to kill a mouse?" << std::endl;
        std::cin >> gramsSweetener;

        std::cout << "What is the weight of the mouse in grams?" << std::endl;
        std::cin >> gramsMouse;

        std::cout << "What is the weight of the dieter in grams?" << std::endl;
        std::cin >> gramsDieter;

        amtOfSoda = ((gramsSweetener / gramsMouse) * gramsDieter) / (percSweetenerSoda * gramsSoda);

        std::cout << "The amount of diet soda can's that would kill the dieter is: " << amtOfSoda << std::endl;

        std::cout << "Would you like to repeat? Y/N" << std::endl;
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    return 0;
}
