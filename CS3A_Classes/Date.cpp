//
// Created by Quantum on 9/30/2021.
//

#include "Date.h"

///getters
int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

int Date::getYear() {
    return year;
}

///setters
void Date::setMonth(int month) {
    this->month = month;
}

void Date::setDay(int day) {
    (*this).day = day;
}

void Date::setYear(int year) {
    Date::year = year;
}

///constructors
Date::Date() = default;
Date::Date(int month, int day, int year) : month(month), day(day), year(year) {

}