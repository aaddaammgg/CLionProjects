#include <iostream>

int checkIfBetween(int i);
std::string getNumberInEnglish(int i);
std::string getOnes(int i);
std::string getTeens(int i);
std::string getTens(int i);
void outputSong(int i);


int main() {
    char repeat;
    int bottles;

    do {
        std::cout << "Enter the amount of bottles:\n";
        std::cin >> bottles;

        outputSong(bottles);

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    return 0;
}

void outputSong(int i) {
    int bottles = checkIfBetween(i);
    std::cout << getNumberInEnglish(bottles) << " bottles of beer on the wall,\n";
    std::cout << getNumberInEnglish(bottles) << " bottles of beer,\n";
    std::cout << "Take one down, pass it around,\n";
    std::cout << getNumberInEnglish(bottles - 1) << " bottles of beer.\n";
}

std::string getNumberInEnglish(int i) {
    int ones = i % 10;
    int tens = i / 10;

    if (i > 9) {
        if (tens == 1) {
            return getTeens(ones);
        } else if (ones == 0){
            return getTens(tens);
        } else {
            return getTens(tens) + "-" + getOnes(ones);
        }
    } else {
        return getOnes(ones);
    }
}

int checkIfBetween(int i) {
    int bottles = i;

    if (i < 0 || i > 99) {
        bottles = 99;
    }

    return bottles;
}

std::string getOnes(int i) {
    switch(i) {
        case 0:
            return "Zero";
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        default:
            return "Zero";
    }
}

std::string getTeens(int i) {
    switch(i) {
        case 0:
            return "Ten";
        case 1:
            return "Eleven";
        case 2:
            return "Twelve";
        case 3:
            return "Thirteen";
        case 4:
            return "Fourteen";
        case 5:
            return "Fifteen";
        case 6:
            return "Sixteen";
        case 7:
            return "Seventeen";
        case 8:
            return "Eighteen";
        case 9:
            return "Nineteen";
        default:
            return "NULL";
    }
}

std::string getTens(int i) {
    switch(i) {
        case 2:
            return "Twenty";
        case 3:
            return "Thirty";
        case 4:
            return "Forty";
        case 5:
            return "Fifty";
        case 6:
            return "Sixty";
        case 7:
            return "Seventy";
        case 8:
            return "Eighty";
        case 9:
            return "Ninety";
        default:
            return "NULL";
    }
}