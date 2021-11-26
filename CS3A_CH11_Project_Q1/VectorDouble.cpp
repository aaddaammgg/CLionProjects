//
// Created by Adam G. on 10/24/2021.
//

#include "VectorDouble.h"

VectorDouble::VectorDouble() {
    this->arr = new double[50];
    this->count = 0;
    this->max_count = 50;
}

VectorDouble::VectorDouble(int max_count) {
    this->arr = new double[max_count];
    this->count = 0;
    this->max_count = 50;
}

VectorDouble::VectorDouble(const VectorDouble &copy) {
    this->count = copy.count;
    this->max_count = copy.max_count;
    this->arr = new double[max_count];

    for (int i = 0; i != count; ++i) {
        arr[i] = copy.arr[i];
    }
}

VectorDouble::~VectorDouble() {
    delete[] arr;
}

VectorDouble VectorDouble::operator=(VectorDouble &copy) {
    if (&copy != this) {
        delete[] arr;
        count = copy.count;
        max_count = copy.max_count;
        arr = new double[max_count];

        for (int i = 0; i != count; ++i) {
            arr[i] = copy.arr[i];
        }
    }
    return *this;
}

bool VectorDouble::operator==(VectorDouble b) const {
    if (b.count == count) {
        for (int i = 0; i < count; ++i) {
            if (arr[i] !=b.arr[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

void VectorDouble::push_back(double num) {
    if (max_count == 0) {
        max_count = 1;
        arr = new double[max_count];
        arr[count] = num;
        count++;
    } else if (max_count > count) {
        arr[count] = num;
        count++;
    } else {
        double *temp = new double[max_count];
        temp = arr;
        resize(2 * max_count, max_count);
        arr= temp;
        arr[count] = num;
        count++;
    }
}

int VectorDouble::capacity() {
    return max_count;
}

int VectorDouble::size() {
    return count;
}

void VectorDouble::reserve(int size) {

}

void VectorDouble::resize(int size, double val) {
    max_count = size;
    arr = new double[val];
}

double VectorDouble::value_at(int i) {
    if (i < count) {
        return arr[i];
    }
    return -1;
}

void VectorDouble::change_value_at(double val, int i) {
    if (i < count) {
        arr[i] = val;
    }
}

std::ostream &operator<<(std::ostream& os, const VectorDouble &val) {
    os << "[ ";
    for (int i = 0; i != val.count; ++i) {
        os << val.arr[i] << " ";
    }
    os << "]" << std::endl;

    return os;
}
