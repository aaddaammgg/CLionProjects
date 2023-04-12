//
// Created by Quantum on 4/11/2023.
//

#ifndef CS_TUTORING_3A_JL_HW_2_TEACHER_H
#define CS_TUTORING_3A_JL_HW_2_TEACHER_H

#include "Person.h"

class Teacher : public Person {
private:
    int code[3];
public:
    int* getCode();
};


#endif //CS_TUTORING_3A_JL_HW_2_TEACHER_H
