//
// Created by Quantum on 4/11/2023.
//

#include "ComputerBook.h"

const std::string &ComputerBook::getPublisher() const {
    return publisher;
}

void ComputerBook::setPublisher(const std::string &publisher) {
    ComputerBook::publisher = publisher;
}

CATEGORY ComputerBook::getCategory() {
    return CATEGORY::COMPUTER_BOOK;
}
