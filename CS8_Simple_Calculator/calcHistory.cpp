//
// Created by Adam G. on 1/16/2022.
//

#include "calcHistory.h"

calcHistory::calcHistory() {

}

void calcHistory::mergeQueue(std::list<double> q1) {

    std::list<double>::iterator  it;
    for (it = q1.begin(); it != q1.end(); ++it) {
        history.push_back(*it);
    }
}

void calcHistory::push(const double val) {
    history.push_back(val);
}

void calcHistory::outputHistory() {
    std::cout << "[HISTORY] START" << std::endl;

    std::list<double>::iterator  it;
    for (it = history.begin(); it != history.end(); ++it) {
        std::cout << ">> " << *it << std::endl;
    }

    std::cout << "[HISTORY] END" << std::endl;
}

calcHistory calcHistory::operator+(const calcHistory &rhs) {
    mergeQueue(rhs.history);

    return *this;
}

calcHistory calcHistory::operator+(const double &rhs) {
    this->history.push_back(rhs);

    return *this;
}

calcHistory calcHistory::operator=(const calcHistory &rhs) {
    if (this == &rhs) {
        return *this;
    }

    history = rhs.history;
    return *this;
}
