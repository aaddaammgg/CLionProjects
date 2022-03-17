#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

void printEq(char op, int tensR, int onesR, int topNum, int botNum, int value, const std::string& sValue);
void printRemainders(int tensR, int onesR, int width);
void printTopNumber(int topNum, int width);
void printBotNumber(char op, int botNum, int width);
void printUnderline(int width);
void printSolution(const std::string& sValue, int width);
void printRepeatMsg(const std::string& msg, int amount);
int getDigits(int num);
int getDigitValue(int num, int digit);
int getOnesR(int topNum, int botNum);
int getTensR(int topNum, int botNum);
int getHighestDigits(int topNum, int botNum, int value);
void add(int topNum, int botNum);
void sub(int topNum, int botNum);
std::string columnName(int column);

enum {ADD = 1, SUB};

int main() {
    char repeat;
    //int x, y;
    std::string problem, sX, sY;

    do {
        std::cout << "Enter a math problem:\n";
        std::cin >> problem;
        int type = ADD;
        bool isBotNum = false;
        for (char& c : problem) {

            if (isdigit(c) && !isBotNum) {
                sX += c;
            } else if (isdigit(c)) {
                sY += c;
            } else {
                isBotNum = true;
                //std::cout << "NO DIGIT " << c << "\n";
            }
            //std::cout << sX << " | " << sY << "\n";
            if (c == '-') {
                type = SUB;
            }
        }
        int iX = std::stoi(sX), iY = std::stoi(sY);

        if (type == ADD) {
            add(iX, iY);
        } else {
            sub(iX, iY);
        }
        sX = "";
        sY = "";


        std::cout << "Would you like to run this program again? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

void add(int topNum, int botNum) {
    int origValue = topNum + botNum;
    int tensR = 0, onesR = 0, value = 0;
    std::string sValue;
    std::string origStrValue = std::to_string(origValue);
    int onesSum = getOnesR(topNum, botNum);
    int tensSum = getTensR(topNum, botNum);
    char op = '+';
    int getValueLength = origStrValue.length();

    printEq(op, tensR, onesR, topNum, botNum, value, sValue);

    int dig = 1;
    for (int i = getValueLength; i > 0; i--) {
        int digValueTop = getDigitValue(topNum, dig);
        int digValueBot = getDigitValue(botNum, dig);
        int digValueTopBotSum = digValueTop + digValueBot;
        if (digValueTop > 0 || digValueBot > 0) {
            std::cout << "Add column " << columnName(abs(i - getValueLength - 1)) << ": " << digValueTop << " + " << digValueBot << " = " << digValueTopBotSum << "\n";
        }
        if (onesSum > 9 && i == getValueLength) {
            onesR = (onesSum / 10) % 10;
            std::cout << "Carry the " << onesR << "\n";
        }
        if (tensSum > 9 && i == getValueLength - 1) {
            tensR = (tensSum / 10) % 10;
            std::cout << digValueTopBotSum << " becomes " << digValueTopBotSum + tensR << "\n";
            std::cout << "Carry the " << tensR << "\n";
        }
        char singleVal = origStrValue.at(i - 1);
        sValue.insert(0, 1, singleVal);

        dig *= 10;
        if ((i == 2) && (tensSum > 9)) {
            sValue = origStrValue;
            i = 0;
            std::cout << digValueTopBotSum << " becomes " << sValue.substr(0,2) << "\n";
            std::cout << "Drop the " << sValue.substr(0,2) << "\n";
        } else {
            std::cout << "Drop the " << singleVal << "\n";
        }
        std::cout << "\n";
        printEq(op, tensR, onesR, topNum, botNum, value, sValue);
    }

}

void sub(int topNum, int botNum) {
    int origValue = topNum - botNum;
    int tensR = 0, onesR = 0, value = 0;
    std::string sValue;
    std::string origStrValue = std::to_string(origValue);
    int tensSum = getTensR(topNum, botNum);
    char op = '-';
    int getValueLength = origStrValue.length();

    printEq(op, tensR, onesR, topNum, botNum, value, sValue);

    int dig = 1;
    for (int i = getValueLength; i > 0; i--) {
        int digValueTop = getDigitValue(topNum, dig);
        int digValueBot = getDigitValue(botNum, dig);
        int digValueTopBotSum = digValueTop - digValueBot;
        if (digValueTop > 0 || digValueBot > 0) {

            if (digValueTopBotSum < 0) {
                std::cout << "Since it is a negative we need to borrow from the next column. " << digValueTopBotSum << " becomes " << digValueTopBotSum + 10 << " by adding 10\n";
            } else {
                std::cout << "Subtract column " << columnName(abs(i - getValueLength - 1)) << ": " << digValueTop << " - " << digValueBot << " = " << digValueTopBotSum << "\n";
            }
        }

        char singleVal = origStrValue.at(i - 1);
        sValue.insert(0, 1, singleVal);

        dig *= 10;
        if ((i == 2) && (tensSum > 9)) {
            sValue = origStrValue;
            i = 0;
            std::cout << digValueTopBotSum << " becomes " << sValue.substr(0,2) << "\n";
            std::cout << "Drop the " << sValue.substr(0,2) << "\n";
        } else {
            std::cout << "Drop the " << singleVal << "\n";
        }
        printEq(op, tensR, onesR, topNum, botNum, value, sValue);
    }

}

std::string columnName(int column) {
    enum {ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

    switch (column) {
        case ONE:
            return "one";
        case TWO:
            return "two";
        case THREE:
            return "three";
        case FOUR:
            return "four";
        case FIVE:
            return "five";
        case SIX:
            return "six";
        case SEVEN:
            return "seven";
        case EIGHT:
            return "eight";
        case NINE:
            return "nine";
        default:
            return "NULL";
    }
}

int getDigitValue(int num, int digit) {
    return (num / digit) % 10;
}

int getOnesR(int topNum, int botNum) {
    int topNumOnes = getDigitValue(topNum, 1);
    int botNumOnes = getDigitValue(botNum, 1);
    int value = topNumOnes + botNumOnes;

    return value;
}

int getTensR(int topNum, int botNum) {
    int topNumOnes = getDigitValue(topNum, 10);
    int botNumOnes = getDigitValue(botNum, 10);
    int value = topNumOnes + botNumOnes;

    return value;
}

int getHundR(int topNum, int botNum) {
    int topNumOnes = (topNum / 100) % 10;
    int botNumOnes = (botNum / 100) % 10;

    int value = topNumOnes + botNumOnes;

    return value;
}

void printEq(char op, int tensR, int onesR, int topNum, int botNum, int value, const std::string& sValue) {
    int highestDigits = getHighestDigits(topNum * 10, botNum * 10, value);

    printRemainders(tensR, onesR, highestDigits);
    printTopNumber(topNum, highestDigits);
    printBotNumber(op, botNum, highestDigits);
    printUnderline(highestDigits);

    if (!sValue.empty()) {
        printSolution(sValue, highestDigits);
    }

    std::cout << "\n\n";
}

void printRemainders(int tensR, int onesR, int width) {
    std::cout << std::right << std::setw(width - 1);

    if (tensR > 0) {
        std::cout << std::right << std::setw(width - 2) << tensR;
    }

    if (onesR > 0) {
        std::cout << onesR;
    }

    std::cout << "\n";
}

void printTopNumber(int topNum, int width) {
    std::cout << std::right << std::setw(width) << topNum << "\n";
}

void printBotNumber(char op, int botNum, int width) {
    std::cout << op << std::right << std::setw(width - 1) << botNum << "\n";
}

void printUnderline(int width) {
    printRepeatMsg("_", width);
    std::cout << "\n";
}

void printSolution(const std::string& sValue, int width) {
    std::cout << std::right << std::setw(width) << sValue << "\n";
}

void printRepeatMsg(const std::string& msg, int amount) {
    for (int i = 0; i < amount; i++) {
        std::cout << msg;
    }
}

int getDigits(int num) {
    int i;

    for(i = 0; num != 0; ++i){
        num /= 10;
    }

    return i;
}

int getHighestDigits(int topNum, int botNum, int value) {
    int highestDigits;
    int digTopNum = getDigits(topNum);
    int digBotNum = getDigits(botNum);
    int digValue = getDigits(value);

    if (digTopNum >= digBotNum && digTopNum >= digValue) {
        highestDigits = digTopNum;
    } else if (digBotNum >= digTopNum && digBotNum >= digValue) {
        highestDigits = digBotNum;
    } else {
        highestDigits = digValue;
    }

    return highestDigits;
}