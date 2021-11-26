//
// Created by Quantum on 9/30/2021.
//

#ifndef CS3A_CLASSES_NAME_H
#define CS3A_CLASSES_NAME_H

#include <string>

class Name {
private:
    std::string firstName, lastName;
    char middleInitial{};
public:
    ///constructors

    ///default constructor
    Name();
    ///overloaded constructor
    Name(std::string firstName, char middleInitial, std::string lastName);

    ///getters or accessors
    std::string getFirstName();
    std::string getLastName();
    char getMiddleInitial();

    ///setters or mutators
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setMiddleInitial(char middleInitial);
};


#endif //CS3A_CLASSES_NAME_H
