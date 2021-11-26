//
// Created by Adam G. on 10/24/2021.
//

#include "Date.h"

Date::Date() {
    *this = getCurrentDate();
}

Date::Date(int month, int day, int year) : month(month), day(day), year(year) {

}

Date Date::getCurrentDate() {
    int lMonth, lDay, lYear;

    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    lMonth = 1 + ltm->tm_mon;
    lDay = ltm->tm_mday;
    lYear = 1900 + ltm->tm_year;

    Date curDate(lMonth, lDay, lYear);

    return curDate;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

std::string Date::getFullMonth(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "January";
    }
}

void Date::replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

std::string Date::getDate(std::string format) {
    if (format.empty())
        format = "m/d/YY";

    std::string sMonth = std::to_string(month), sDay = std::to_string(day), sYear = std::to_string(year);
    replaceAll(format, "YY", sYear);
    replaceAll(format, "Y", sYear.substr(sYear.length() - 2));
    replaceAll(format, "MM", getFullMonth(month));
    replaceAll(format, "M", getFullMonth(month).substr(0, 3));
    replaceAll(format, "m", sMonth);
    replaceAll(format, "d", sDay);
    return format;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setYear(int year) {
    this->year = year;
}

std::ostream &operator<<(std::ostream &os, const Date &x) {
    os << x.month << "/" << x.day << "/" << x.year;
    return os;
}

Date operator+(Date& x, const int &y) {
    x.setYear(x.getYear() + y);
    return x;
}

Date operator-(Date &x, const int &y) {
    x.setYear(x.getYear() - y);
    return x;
}
