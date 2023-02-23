#include <iostream>
#include "Course.h"

int main() {
    int numberOfCourses = -1;
    int totalStudents = 0;

    std::cout << "Enter the number of courses: " << std::endl;
    std::cin >> numberOfCourses;

    Course* courses = new Course[numberOfCourses];

    for (int i = 0; i < numberOfCourses; ++i) {
        courses[i] = createCourse();
        totalStudents += courses[i].studentCount;
    }

    int* studentIDs = new int[totalStudents];

    int start = 0, end = 0;
    for (int i = 0; i < numberOfCourses; ++i) {
        //printCourse(courses[i]);

        end += courses[i].studentCount;

        if (i > 0) {
            start += courses[i - 1].studentCount;
        }

        std::cout << "Start: " << start << " End: " << end << std::endl;



        for (int j = 0; j < courses[i].studentCount; ++j) {
            Student* student = &courses[i].students[j];
            studentIDs[start + j] = student->getID();
        }
    }

    for (int i = 0; i < totalStudents; ++i) {
        std::cout << "ID: " << studentIDs[i] << std::endl;
    }
    return 0;
}
