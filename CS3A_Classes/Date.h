//
// Created by Quantum on 9/30/2021.
//

#ifndef CS3A_CLASSES_DATE_H
#define CS3A_CLASSES_DATE_H


class Date {
private:
    int month{}, day{}, year{};
public:
    ///getters
    int getMonth();
    int getDay();
    int getYear();

    ///setters
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);

    ///constructors
    Date();
    Date(int month, int day, int year);
};


#endif //CS3A_CLASSES_DATE_H
