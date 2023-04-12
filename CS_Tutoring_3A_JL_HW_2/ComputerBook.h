//
// Created by Quantum on 4/11/2023.
//

#ifndef CS_TUTORING_3A_JL_HW_2_COMPUTERBOOK_H
#define CS_TUTORING_3A_JL_HW_2_COMPUTERBOOK_H

#include <string>
#include "Book.h"

class ComputerBook : public Book {
private:
    std::string publisher;
public:
    const std::string &getPublisher() const;

    void setPublisher(const std::string &publisher);

    CATEGORY getCategory() override;
};


#endif //CS_TUTORING_3A_JL_HW_2_COMPUTERBOOK_H
