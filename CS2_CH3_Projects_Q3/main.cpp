#include <iostream>
#include <string>

/*
 * I = 1
 * V = 5
 * X = 10
 * L = 50
 * C = 100
 * D = 500
 * M = 1000
 */

int main() {
    char repeat;
    std::string roman;
    int integer, integerOG, piece;

    do {
        std::cout << "Enter a year between 1000 and 3000:" << std::endl;
        std::cin >> integer;
        integerOG = integer;

        if (integer < 1000 || integer > 3000) {
            std::cout << "Invalid year. Please try again." << std::endl;
            repeat = 'Y';
            continue;
        }

        roman = "";

        if (integer >= 1000) {
            piece = integer / 1000;

            for (int i = 0; i < piece; i++) {
                roman += 'M';
            }

            integer %= 1000;
        }

        if (integer >= 100) {
            piece = integer / 100;

            if (piece == 9) {
                roman += "CM";
            } else if (piece >= 5){
                roman += 'D';

                for (int i = 0; i < piece - 5; i++) {
                    roman += 'C';
                }
            } else if (piece == 4) {
                roman += "CD";
            } else if (piece >= 1) {
                for (int i = 0; i < piece; i++) {
                    roman += 'C';
                }
            }

            integer %= 100;
        }

        if (integer >= 10) {
            piece = integer / 10;

            if (piece == 9) {
                roman += "XC";
            } else if (piece >= 5) {
                roman += 'L';

                for (int i = 0; i < piece - 5; i++) {
                    roman += 'X';
                }
            } else if (piece == 4) {
                roman += "XL";
            } else if (piece >= 1) {
                for (int i = 0; i < piece; i++) {
                    roman += 'X';
                }
            }

            integer %= 10;
        }

        if (integer >= 1) {
            piece = integer;

            if (piece == 9) {
                roman += "IX";
            } else if (piece >= 5) {
                roman += 'V';

                for (int i = 0; i < piece - 5; i++) {
                    roman += 'I';
                }
            } else if (piece == 4) {
                roman += "IV";
            } else if (piece >= 1) {
                for (int i = 0; i < piece; i++) {
                    roman += 'I';
                }
            }
        }

        std::cout << integerOG << " is " << roman << " in roman numeral" << std::endl;

        std::cout << "Would you like to repeat? Y/N" << std::endl;
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
