#include <iostream>

//#include "Person.h"
#include "Child.h"


int main() {



    Name name("Vanessa", 'R', "Malaninas");
    Name name2;

    Date date;
    date.setMonth(10);
    date.setDay(28);
    date.setYear(1977);

    Child bob(name, date);
    bob.setShoeSize(10);

    Person vanessa;
    vanessa.setName(name);
    vanessa.setBirthday(date);

    std::cout << name.getFirstName() << std::endl;

    return 0;
}
