//
// Created by Adam G. on 2/22/23.
//

#include "Student.h"

int Student::getID() {
    return m_id;
}

std::string Student::getName() {
    return m_name;
}

int Student::getScore() {
    return m_score;
}

void Student::setID(const int& id) {
    m_id = id;
}

void Student::setName(const std::string& name) {
    m_name = name;
}

void Student::setScore(const int& score) {
    m_score = score;
}
