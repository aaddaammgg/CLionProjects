//
// Created by Adam G. on 2/22/23.
//
#include <iostream>
#include <string>

#ifndef CS_TUTORING_DYNAMICSTUDENTCOURSES_STUDENT_H
#define CS_TUTORING_DYNAMICSTUDENTCOURSES_STUDENT_H


class Student {
private:
    int m_id = -1;
    std::string m_name;
    int m_score = -1;
public:
    Student() = default;

    int getID();
    std::string getName();
    int getScore();

    void setID(const int& id);
    void setName(const std::string& name);
    void setScore(const int& score);
};


#endif //CS_TUTORING_DYNAMICSTUDENTCOURSES_STUDENT_H
