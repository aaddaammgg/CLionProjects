//
// Created by Quantum on 4/11/2023.
//

#ifndef CS_TUTORING_3A_JL_HW_2_NOVEL_H
#define CS_TUTORING_3A_JL_HW_2_NOVEL_H

#include "Book.h"

class Novel : public Book {
private:
    int publish_date;
public:
    int getPublishDate() const;

    void setPublishDate(int publishDate);

    CATEGORY getCategory() override;
};


#endif //CS_TUTORING_3A_JL_HW_2_NOVEL_H
