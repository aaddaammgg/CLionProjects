//
// Created by Adam G. on 12/10/2021.
//

#ifndef CS3A_CH15_PROJECT_Q3_PERSON_H
#define CS3A_CH15_PROJECT_Q3_PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string name;
public:
    Person();
    Person(std::string name);
    Person(const Person& object);

    std::string getName() const;

    Person& operator=(const Person& rhs);
    friend std::istream& operator>>(std::istream& is, Person& person);
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};


#endif //CS3A_CH15_PROJECT_Q3_PERSON_H
