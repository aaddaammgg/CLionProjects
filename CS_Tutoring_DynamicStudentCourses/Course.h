//
// Created by Adam G. on 2/22/23.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Student.h"

#ifndef CS_TUTORING_DYNAMICSTUDENTCOURSES_COURSE_H
#define CS_TUTORING_DYNAMICSTUDENTCOURSES_COURSE_H

struct Course {
    std::string courseName;
    int studentCount = 0;
    Student* students = nullptr;
};

static void printFilled(char c, int amt) {
    std::cout << std::setfill(c) << std::setw(amt) << c << std::setfill(' ') << std::endl;
}

static void printCourse(const Course& course) {
    std::cout << "Course Name: " << course.courseName << std::endl;
    std::cout << "Class Size: " << course.studentCount << std::endl;

    printFilled('-', 33);

    for (int i = 0; i < course.studentCount; ++i) {
        Student* student = &course.students[i];
        std::cout << std::setw(10) << student->getID() << std::setw(15) << student->getName() << std::setw(5) << student->getScore() << std::endl;
    }

    std::cout << std::endl;
    printFilled('=', 33);
}

static Course createCourse(const std::string& fileName) {
    std::ifstream file;

    file.open(fileName);

    std::cout << "Opening file... " << fileName << std::endl;

    if (file.fail()) {
        std::cout << "Error opening file..." << std::endl;
        exit(1);
    }

    std::string courseName;
    int studentCount;

    file >> courseName >> studentCount;

    int id, score, i = 0;
    std::string name;

    Student* students = new Student[studentCount];

    while (file >> id >> name >> score) {
        students[i].setID(id);
        students[i].setName(name);
        students[i].setScore(score);

        i++;
    }

    file.close();

    return Course{courseName, studentCount, students};
}

static Course createCourse() {
    std::string fileName;

    std::cout << "Enter filename: ";
    std::cin >> fileName;
    std::cout << std::endl;

    return createCourse(fileName);
}

#endif //CS_TUTORING_DYNAMICSTUDENTCOURSES_COURSE_H
