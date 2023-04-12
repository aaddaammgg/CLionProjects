//
// Created by Quantum on 4/11/2023.
//

#ifndef CS_TUTORING_3A_JL_HW_2_BOOK_H
#define CS_TUTORING_3A_JL_HW_2_BOOK_H

#include <string>

class Book {
private:
    int code;
    std::string title;
    int available;
    int rented;
public:
    virtual int getCode();
    virtual std::string getTitle();
    virtual int getAvailable();
    virtual int getRented();

    virtual void setCode(int code);
    virtual void setTitle(const std::string &title);
    virtual void setAvailable(int available);
    virtual void setRented(int rented);
};


#endif //CS_TUTORING_3A_JL_HW_2_BOOK_H
