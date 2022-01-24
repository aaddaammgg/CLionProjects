#include <iostream>
#include "calcBase.h"
#include "calcAdd.h"
#include "calcHistory.h"

int main() {

    calcBase::welcomeMsg();

    calcHistory history;

    calcAdd prob1;
    calcAdd prob2;

    history = prob1.getHistory() + prob2.getHistory();

    history.outputHistory();

    return 0;
}