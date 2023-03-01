#include <iostream>
#include <algorithm>
#include "Course.h"

typedef enum {
    ID,
    SCORE
} STUD_TYPE;

void studentsTakingAllCourses(Course* courses);
void studentsTakingAllCourses(Course* courses, int numCourses);
bool getConditionType(const Student& student1, const Student& student2, STUD_TYPE type);
void sortCourse(Student* list, const int &len, STUD_TYPE type);

int main() {
    std::string fileNames[] = {"cpp.txt", "java.txt", "python.txt"};

    int numberOfCourses = (sizeof fileNames / sizeof fileNames[0]);
    int totalStudents = 0;

    Course* courses = new Course[numberOfCourses];

    for (int i = 0; i < numberOfCourses; ++i) {
        courses[i] = createCourse(fileNames[i]);
        totalStudents += courses[i].studentCount;
    }

//    int* studentIDs = new int[totalStudents];
//
//    int start = 0, end = 0;
//    for (int i = 0; i < numberOfCourses; ++i) {
//        //printCourse(courses[i]);
//
//        end += courses[i].studentCount;
//
//        if (i > 0) {
//            start += courses[i - 1].studentCount;
//        }
//
//        std::cout << "Start: " << start << " End: " << end << std::endl;
//
//        for (int j = 0; j < courses[i].studentCount; ++j) {
//            Student* student = &courses[i].students[j];
//            studentIDs[start + j] = student->getID();
//        }
//    }

//    for (int i = 0; i < totalStudents; ++i) {
//        std::cout << "ID: " << studentIDs[i] << std::endl;
//    }

    studentsTakingAllCourses(courses, numberOfCourses);


//    int& len1 = courses[0].studentCount;
//    int& len2 = courses[1].studentCount;
//    int& len3 = courses[2].studentCount;
//
//    Student* arr1 = courses[0].students;
//    Student* arr2 = courses[1].students;
//    Student* arr3 = courses[2].students;
//
//    sortCourse(arr1, len1, STUD_TYPE::SCORE);
//    sortCourse(arr2, len2, STUD_TYPE::SCORE);
//    sortCourse(arr3, len3, STUD_TYPE::SCORE);
//
//    for (int i = 0; i < numberOfCourses; ++i) {
//        printCourse(courses[i]);
//    }

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

void studentsTakingAllCourses(Course* courses, int numCourses)
{
    int maxStudentCount = 0;
    for (int i = 0; i < numCourses; i++) {
        maxStudentCount = std::max(maxStudentCount, courses[i].studentCount);
    }

    Student** arr = new Student*[numCourses];
    int* len = new int[numCourses];

    for (int i = 0; i < numCourses; i++) {
        len[i] = courses[i].studentCount;
        arr[i] = new Student[len[i]];
        memcpy(arr[i], courses[i].students, len[i] * sizeof(Student));
        sortCourse(arr[i], len[i], STUD_TYPE::ID);
    }

    int* indices = new int[numCourses];
    std::fill_n(indices, numCourses, 0);

    bool done = false;
    while (!done) {
        int minID = arr[0][indices[0]].getID();
        for (int i = 1; i < numCourses; i++) {
            while (indices[i] < len[i] && arr[i][indices[i]].getID() < minID) {
                indices[i]++;
            }
            if (indices[i] == len[i]) {
                done = true;
                break;
            }
            if (arr[i][indices[i]].getID() > minID) {
                minID = arr[i][indices[i]].getID();
            }
        }
        if (!done) {
            bool found = true;
            for (int i = 0; i < numCourses; i++) {
                if (arr[i][indices[i]].getID() != minID) {
                    found = false;
                    indices[i]++;
                    break;
                }
            }
            if (found) {
                std::cout << ' ' << minID;
                std::cout << std::setw(10) << arr[0][indices[0]].getName();
                for (int i = 0; i < numCourses; i++) {
                    std::cout << "  " << courses[i].courseName << '(';
                    std::cout << arr[i][indices[i]].getScore() << ") ";
                }
                std::cout << std::endl;
                for (int i = 0; i < numCourses; i++) {
                    indices[i]++;
                }
            }
        }
    }

    for (int i = 0; i < numCourses; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] len;
    delete[] indices;
}


//void studentsTakingAllCourses(Course* courses, int numCourses)
//{
//    int maxStudentCount = 0;
//    for (int i = 0; i < numCourses; i++) {
//        maxStudentCount = std::max(maxStudentCount, courses[i].studentCount);
//    }
//
//    for (int i = 0; i < numCourses; i++) {
//        int& len = courses[i].studentCount;
//        Student* students = courses[0].students;
//        sortCourse(students, len, STUD_TYPE::ID);
//    }
//
//    int* indices = new int[numCourses];
//    std::fill_n(indices, numCourses, 0);
//
//    bool done = false;
//    while (!done) {
//        int minID = arr[0][indices[0]].getID();
//        for (int i = 1; i < numCourses; i++) {
//            while (indices[i] < len[i] && arr[i][indices[i]].getID() < minID) {
//                indices[i]++;
//            }
//            if (indices[i] == len[i]) {
//                done = true;
//                break;
//            }
//            if (arr[i][indices[i]].getID() > minID) {
//                minID = arr[i][indices[i]].getID();
//            }
//        }
//        if (!done) {
//            bool found = true;
//            for (int i = 0; i < numCourses; i++) {
//                if (arr[i][indices[i]].getID() != minID) {
//                    found = false;
//                    indices[i]++;
//                    break;
//                }
//            }
//            if (found) {
//                std::cout << ' ' << minID;
//                std::cout << std::setw(10) << arr[0][indices[0]].getName();
//                for (int i = 0; i < numCourses; i++) {
//                    std::cout << "  " << courses[i].courseName << '(';
//                    std::cout << arr[i][indices[i]].getScore() << ") ";
//                }
//                std::cout << std::endl;
//                for (int i = 0; i < numCourses; i++) {
//                    indices[i]++;
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < numCourses; i++) {
//        delete[] arr[i];
//    }
//    delete[] arr;
//    delete[] len;
//    delete[] indices;
//}



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