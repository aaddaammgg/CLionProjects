//
// Created by Adam G. on 9/30/2021.
//

#include "Value.h"

double Value::getValue() const {
    return value;
}

Value::Value() : Value(0) {

}

Value::Value(double value) : value(value) {

}