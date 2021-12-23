//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PRACTICE_Q3_RECTANGLE_H
#define CS3A_CH15_PRACTICE_Q3_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    int width;
    int height;
public:
    Rectangle();
    Rectangle(int width, int height);

    virtual double getArea();
    int getWidth() const;
    int getHeight() const;

    void setWidth(int newWidth);
    void setHeight(int newHeight);
};


#endif //CS3A_CH15_PRACTICE_Q3_RECTANGLE_H
