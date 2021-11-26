//
// Created by Adam G. on 9/30/2021.
//

#ifndef CS3A_LAB_MIDPOINT_VALUE_H
#define CS3A_LAB_MIDPOINT_VALUE_H

class Value {
private:
    double value{};
public:
    double getValue() const;

    Value();
    Value(double value);
};


#endif //CS3A_LAB_MIDPOINT_VALUE_H
