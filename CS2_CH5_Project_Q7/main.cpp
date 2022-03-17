#include <iostream>

bool isLeapYear(int year);
bool divisibleByNum(int num, int check);

int getYearValue(int year);
int getCenturyValue(int year);
int getFirstTwoDigits(int year);
int getLastTwoDigits(int year);
int getMonthVa0lue(int month, int year);

std::string dayOfWeek(int month, int day, int year);
std::string convertNumToDay(int num);

int main() {
    std::cout << dayOfWeek(5, 11, 2000) << std::endl;
    return 0;
}

bool isLeapYear(int year) {
    return divisibleByNum(400, year) || (divisibleByNum(4, year) && !divisibleByNum(100, year));
}

int getCenturyValue(int year) {
    int twoDigits = getFirstTwoDigits(year);
    int remainder = twoDigits % 4;
    int value = 3 - remainder;

    return value * 2;
}

int getFirstTwoDigits(int year) {
    return year / 100;
}

int getYearValue(int year) {
    int lastTwoDigits = getLastTwoDigits(year);
    int value = lastTwoDigits / 4;

    return value + lastTwoDigits;
}

int getMonthVa0lue(int month, int year) {
    enum months {
        JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
    };

    switch(month) {
        case JAN:
            if (isLeapYear(year)) {
                return 6;
            }

            return 0;
        case FEB:
            if (isLeapYear(year)) {
                return 2;
            }

            return 3;
        case MAR:
        case NOV:
            return 3;
        case APR:
        case JUL:
            return 6;
        case MAY:
            return 1;
        case JUN:
            return 4;
        case AUG:
            return 2;
        case SEP:
        case DEC:
            return 5;
        case OCT:
            return 0;
    }
}

int getLastTwoDigits(int year) {
    return year % 100;
}

std::string dayOfWeek(int month, int day, int year) {
    int centuryVal = getCenturyValue(year);
    int monthVal = getMonthVa0lue(month, year);
    int yearVal = getYearValue(year);
    int value = centuryVal + monthVal;

    value += yearVal + day;

    int remainder = value % 7;

    return convertNumToDay(remainder);
}

std::string convertNumToDay(int num) {
    enum days {Su, Mo, Tu, We, Th, Fr, Sa};\

    switch (num) {
        case Su: return "Sunday";
        case Mo: return "Monday";
        case Tu: return "Tuesday";
        case We: return "Wednesday";
        case Th: return "Thursday";
        case Fr: return "Friday";
        case Sa: return "Saturday";
        default: return "NULL";
    }
}

bool divisibleByNum(int num, int check) {
    return check % num == 0;
}