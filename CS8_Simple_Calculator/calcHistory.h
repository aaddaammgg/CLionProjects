//
// Created by Adam G. on 1/16/2022.
//

#ifndef CS8_SIMPLE_CALCULATOR_CALCHISTORY_H
#define CS8_SIMPLE_CALCULATOR_CALCHISTORY_H

#include "iostream"
#include "list"

class calcHistory {
private:
    std::list<double> history;
    void mergeQueue(std::list<double> q1);
public:
    calcHistory();

    void push(const double val);
    void outputHistory();

    calcHistory operator+(const calcHistory& rhs);
    calcHistory operator+(const double& rhs);
    calcHistory operator=(const calcHistory& rhs);
};


#endif //CS8_SIMPLE_CALCULATOR_CALCHISTORY_H
