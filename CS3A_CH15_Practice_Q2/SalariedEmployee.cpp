//
// Created by Adam G. on 12/10/2021.
//

#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee() {

}

SalariedEmployee::SalariedEmployee(std::string the_name, std::string the_ssn, double the_weekly_salary) {
    set_name(the_name);
    set_ssn(the_ssn);
    set_salary(the_weekly_salary);
}

double SalariedEmployee::get_salary() const {
    return salary;
}

void SalariedEmployee::set_salary(double new_salary) {
    salary = new_salary;
}

void SalariedEmployee::print_check() {
    std::cout << "salary: " << get_salary();
}
