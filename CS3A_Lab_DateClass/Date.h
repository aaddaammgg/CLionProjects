//
// Created by Adam G. on 10/24/2021.
//

#ifndef CS3A_LAB_DATECLASS_DATE_H
#define CS3A_LAB_DATECLASS_DATE_H

#include <ostream>
#include <ctime>

class Date {
private:
    int month, day, year;
    static void replaceAll(std::string& str, const std::string& from, const std::string& to);
    static std::string getFullMonth(int month);
public:
    Date();
    Date(int month, int day, int year);

    int getMonth() const;
    int getDay() const;
    int getYear() const;
    static Date getCurrentDate();
    std::string getDate(std::string format);

    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);

    friend std::ostream& operator<<(std::ostream& os, const Date& x);
    friend Date operator+(Date& x, const int &y);
    friend Date operator-(Date& x, const int &y);
};


#endif //CS3A_LAB_DATECLASS_DATE_H
