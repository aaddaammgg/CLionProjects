//
// Created by Quantum on 4/11/2023.
//

#ifndef CS_TUTORING_3A_JL_HW_2_PERSON_H
#define CS_TUTORING_3A_JL_HW_2_PERSON_H

#include <string>

class Person {
private:
    int id;
    std::string name;
    int count;
public:
    virtual int getID() const;
    virtual const std::string &getName() const;
    virtual int getCount() const;

    virtual void setId(int id);
    virtual void setName(const std::string &name);
    virtual void setCount(int count);
};


#endif //CS_TUTORING_3A_JL_HW_2_PERSON_H
