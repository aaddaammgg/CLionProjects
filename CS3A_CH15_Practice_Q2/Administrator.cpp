//
// Created by Adam G. on 12/10/2021.
//

#include "Administrator.h"

Administrator::Administrator() {

}

void Administrator::set_supervisor(std::string supervisor) {
    immediateSupervisor = supervisor;
}

void Administrator::print() {
    std::cout << "adminTitle: " << adminTitle << "responsibility: " << responsibility << "immediateSupervisor: " << immediateSupervisor << std::endl;
}

void Administrator::print_check() {
    SalariedEmployee::print_check();
}
