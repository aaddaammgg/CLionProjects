//
// Created by Adam G. on 12/10/2021.
//

#include "Employee.h"

Employee::Employee() : name("No name yet"), ssn("No number yet"), net_pay(0) {

}

Employee::Employee(std::string the_name, std::string the_ssn) : name(the_name), ssn(the_ssn), net_pay(0) {

}

std::string Employee::get_name() const {
    return name;
}

std::string Employee::get_ssn() const {
    return ssn;
}

double Employee::get_net_pay() const {
    return net_pay;
}

void Employee::set_name(std::string new_name) {
    name = new_name;
}

void Employee::set_ssn(std::string new_ssn) {
    ssn = new_ssn;
}

void Employee::set_net_pay(double new_net_pay) {
    net_pay = new_net_pay;
}

void Employee::print_check() const {
    std::cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
    << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
    << "Check with the author of the program about this bug.\n";
}
