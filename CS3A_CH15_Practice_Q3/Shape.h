//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PRACTICE_Q3_SHAPE_H
#define CS3A_CH15_PRACTICE_Q3_SHAPE_H

#include <string>

class Shape {
private:
    std::string name;
public:
    Shape();
    Shape(std::string name);

    virtual double getArea() = 0;
    std::string getName();

    void setName(std::string newName);
};


#endif //CS3A_CH15_PRACTICE_Q3_SHAPE_H
