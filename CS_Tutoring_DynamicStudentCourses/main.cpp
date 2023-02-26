#include <iostream>
#include <algorithm>
#include "Course.h"

typedef enum {
    ID,
    SCORE
} STUD_TYPE;

void studentsTakingAllCourses(Course* courses);
bool getConditionType(const Student& student1, const Student& student2, STUD_TYPE type);
void sortCourse(Student* list, const int &len, STUD_TYPE type);

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

//    for (int i = 0; i < totalStudents; ++i) {
//        std::cout << "ID: " << studentIDs[i] << std::endl;
//    }

    studentsTakingAllCourses(courses);


    int& len1 = courses[0].studentCount;
    int& len2 = courses[1].studentCount;
    int& len3 = courses[2].studentCount;

    Student* arr1 = courses[0].students;
    Student* arr2 = courses[1].students;
    Student* arr3 = courses[2].students;

    sortCourse(arr1, len1, STUD_TYPE::SCORE);
    sortCourse(arr2, len2, STUD_TYPE::SCORE);
    sortCourse(arr3, len3, STUD_TYPE::SCORE);

    for (int i = 0; i < numberOfCourses; ++i) {
        printCourse(courses[i]);
    }

    return 0;
}


bool getConditionType(const Student& student1, const Student& student2, STUD_TYPE type) {
    switch (type) {
        case ID:
            return student1.getID() > student2.getID();
        case SCORE:
            return student1.getScore() > student2.getScore();
    }

    return false;
}

void sortCourse(Student* list, const int &len, STUD_TYPE type) {
    for(int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (getConditionType(list[i], list[j], type)) {
                std::swap(list[i], list[j]);
            }
        }
    }
}

void studentsTakingAllCourses(Course* courses)
{
    int& len1 = courses[0].studentCount;
    int& len2 = courses[1].studentCount;
    int& len3 = courses[2].studentCount;

    Student* arr1 = courses[0].students;
    Student* arr2 = courses[1].students;
    Student* arr3 = courses[2].students;

    sortCourse(arr1, len1, STUD_TYPE::ID);
    sortCourse(arr2, len2, STUD_TYPE::ID);
    sortCourse(arr3, len3, STUD_TYPE::ID);

    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2 && k < len3) {
        if (arr1[i].getID() == arr2[j].getID() && arr2[j].getID() == arr3[k].getID()) {

            std::cout << ' ' << arr1[i].getID();
            std::cout << std::setw(10) << arr1[i].getName();
            std::cout << "  " << courses[0].courseName << '(';
            std::cout << arr1[i].getScore() << ") ";
            std::cout << courses[1].courseName << '(';
            std::cout << arr2[j].getScore() << ") ";
            std::cout << courses[2].courseName << '(';
            std::cout << arr3[k].getScore() << ')' << std::endl;

            i++;
            j++;
            k++;
        } else if (arr1[i].getID() < arr2[j].getID()) {
            i++;
        } else if (arr2[j].getID() < arr3[k].getID()) {
            j++;
        } else {
            k++;
        }
    }
}