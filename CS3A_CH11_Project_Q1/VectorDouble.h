//
// Created by Adam G. on 10/24/2021.
//

#ifndef CS3A_CH11_PROJECT_Q1_VECTORDOUBLE_H
#define CS3A_CH11_PROJECT_Q1_VECTORDOUBLE_H

#include <ostream>

class VectorDouble {
private:
    int max_count;
    int count;
    double *arr;

public:
    VectorDouble();
    VectorDouble(int max_count);
    VectorDouble(const VectorDouble& copy);

    ~VectorDouble();
    VectorDouble operator=(VectorDouble& copy);
    bool operator==(VectorDouble b) const;

    void push_back(double num);
    int capacity();
    int size();
    void reserve(int size);
    void resize(int size, double val = 0.0);
    double value_at(int i);
    void change_value_at(double val, int i);
    friend std::ostream& operator<<(std::ostream& os, const VectorDouble &val);
};


#endif //CS3A_CH11_PROJECT_Q1_VECTORDOUBLE_H
