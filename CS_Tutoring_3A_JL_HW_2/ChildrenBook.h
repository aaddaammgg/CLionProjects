//
// Created by Quantum on 4/11/2023.
//

#ifndef CS_TUTORING_3A_JL_HW_2_CHILDRENBOOK_H
#define CS_TUTORING_3A_JL_HW_2_CHILDRENBOOK_H

#include "Book.h"

class ChildrenBook : public Book {
public:
    int getAge() const;
//    std::string getString() override;

    void setAge(int age);
private:
    int age;
};


#endif //CS_TUTORING_3A_JL_HW_2_CHILDRENBOOK_H
