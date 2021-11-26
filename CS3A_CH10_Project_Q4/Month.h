//
// Created by Adam G. on 10/5/2021.
//

#ifndef CS3A_CH10_PROJECT_Q4_MONTH_H
#define CS3A_CH10_PROJECT_Q4_MONTH_H


#include <string>

class Month {
private:
    int month;
    char firstLetter, secondLetter, thirdLetter;
    void intToChar(int month);
    void charToInt(char firstLetter, char secondLetter, char thirdLetter);
public:
    Month(char firstLetter, char secondLetter, char thirdLetter);
    Month(int month);
    Month();

    void setMonth(int month);
    void setMonth(char firstLetter, char secondLetter, char thirdLetter);

    int getMonth();
    std::string getMonthAsLetters();

};


#endif //CS3A_CH10_PROJECT_Q4_MONTH_H
