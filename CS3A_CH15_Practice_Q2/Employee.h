//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PRACTICE_Q1_EMPLOYEE_H
#define CS3A_CH15_PRACTICE_Q1_EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    std::string ssn;
    double net_pay;
public:
    Employee();
    Employee(std::string the_name, std::string the_ssn);

    std::string get_name() const;
    std::string get_ssn() const;
    double get_net_pay() const;

    void set_name(std::string new_name);
    void set_ssn(std::string new_ssn);
    void set_net_pay(double new_net_pay);

    void print_check() const;
};


#endif //CS3A_CH15_PRACTICE_Q1_EMPLOYEE_H
