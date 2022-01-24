//
// Created by Adam G. on 1/16/2022.
//

#ifndef CS8_SIMPLE_CALCULATOR_CALCBASE_H
#define CS8_SIMPLE_CALCULATOR_CALCBASE_H

#include <iostream>
#include "calcInputsENUMS.h"
#include "calcArithmeticTypeENUMS.h"
#include "calcHistory.h"

class calcBase {
private:
    double x;
    double y;
    double result = 0;
    calcHistory history;
public:
    calcBase();
    calcBase(double x, double y);

    static void welcomeMsg();
    void calculateResult(ArithmeticTypeENUM at);
    void outputResult(ArithmeticTypeENUM at) const;
    void getUserInput(inputENUM val);

    calcHistory getHistory();
    void setHistory(calcHistory his);

    double getX() const;
    double getY() const;
    double getResult() const;

    void setX(double x);
    void setY(double y);
    void setResult(double val);

};


#endif //CS8_SIMPLE_CALCULATOR_CALCBASE_H
