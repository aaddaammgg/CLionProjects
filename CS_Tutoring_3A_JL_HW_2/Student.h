//
// Created by Quantum on 4/11/2023.
//

#ifndef CS_TUTORING_3A_JL_HW_2_STUDENT_H
#define CS_TUTORING_3A_JL_HW_2_STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int code[2];
public:
    int* getCode();
};


#endif //CS_TUTORING_3A_JL_HW_2_STUDENT_H
