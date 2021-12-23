//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PRACTICE_Q1_SALARIEDEMPLOYEE_H
#define CS3A_CH15_PRACTICE_Q1_SALARIEDEMPLOYEE_H

#include "Employee.h"
#include <string>
#include <iostream>

class SalariedEmployee : public Employee {
protected:
    double salary;
public:
    SalariedEmployee();
    SalariedEmployee(std::string the_name, std::string the_ssn, double the_weekly_salary);

    double get_salary() const;
    void set_salary(double new_salary);

    void print_check();
};


#endif //CS3A_CH15_PRACTICE_Q1_SALARIEDEMPLOYEE_H
