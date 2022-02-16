//
// Created by Adam Gonzalez on 1/26/22.
//

#ifndef INHERITANCE_PERSON_H
#define INHERITANCE_PERSON_H

#include <string>

class Person {
private:
    std::string firstName, lastName, middleName;
public:
    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getMiddleName() const;

    void setMiddleName(const std::string &middleName);
};


#endif //INHERITANCE_PERSON_H
