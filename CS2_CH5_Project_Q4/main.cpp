#include <iostream>

void compute_coins(int coin_value, int &num, int &amount_left);

int main() {
    int num, amount_left;
    char repeat;
    do {
        do {
            std::cout << "Enter the amount of change in cents. (1-99):\n";
            std::cin >> num;
        } while(num < 1 || num > 99);

        std::cout << num << " cents can be given as\n";
        compute_coins(25, num, amount_left);
        std::cout << amount_left << " quarter(s) ";

        compute_coins(10, num, amount_left);
        std::cout << amount_left << " dimes(s) ";
        std::cout << num << " penny(pennies)\n\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while(repeat == 'Y' || repeat == 'y');

    return 0;
}

void compute_coins(int coin_value, int &num, int &amount_left)
{
    amount_left = num / coin_value;
    num -= amount_left * coin_value;
}