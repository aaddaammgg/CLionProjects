//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PRACTICE_Q3_CIRCLE_H
#define CS3A_CH15_PRACTICE_Q3_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int radius;
public:
    Circle();
    Circle(int radius);

    virtual double getArea();
    double getRadius();

    void setRadius(int newRadius);
};


#endif //CS3A_CH15_PRACTICE_Q3_CIRCLE_H
