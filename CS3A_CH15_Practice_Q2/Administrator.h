//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PRACTICE_Q1_ADMINISTRATOR_H
#define CS3A_CH15_PRACTICE_Q1_ADMINISTRATOR_H

#include <utility>
#include "SalariedEmployee.h"

class Administrator : SalariedEmployee {
private:
    std::string adminTitle;
    std::string responsibility;
    std::string immediateSupervisor;
protected:
    double annualSalary;
public:
    Administrator();

    void set_supervisor(std::string supervisor);

    void print();
    void print_check();
};


#endif //CS3A_CH15_PRACTICE_Q1_ADMINISTRATOR_H
