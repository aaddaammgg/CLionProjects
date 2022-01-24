//
// Created by Adam G. on 1/16/2022.
//

#include "calcAdd.h"

calcAdd::calcAdd() {
    calcBase::getUserInput(INPUT_X);
    calcBase::getUserInput(INPUT_Y);
    calcBase::calculateResult(AT_ADD);
    calcBase::outputResult(AT_ADD);
}