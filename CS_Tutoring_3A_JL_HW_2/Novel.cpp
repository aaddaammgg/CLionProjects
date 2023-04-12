//
// Created by Quantum on 4/11/2023.
//

#include "Novel.h"

int Novel::getPublishDate() const {
    return publish_date;
}

void Novel::setPublishDate(int publishDate) {
    publish_date = publishDate;
}

CATEGORY Novel::getCategory() {
    return CATEGORY::NOVEL;
}
