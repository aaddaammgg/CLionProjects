/*
 * Adam Gonzalez
 * Project 0
 * Program works
 * CLion IDE
 */

#include <iostream>
#include <iomanip>

double enterGrade(const std::string& name) {
    double grade;

    std::cout << "Enter " << name << " grade (EX: 94.7): ";
    std::cin >> grade;

    return grade;
}

int main() {
    std::cout << "Adam Gonzalez (10275803)" << std::endl;
    std::cout << std::endl;

    double midterm, final, project1, project2, project3, quiz1, quiz2;

    midterm = enterGrade("midterm");
    final = enterGrade("final exam");
    project1 = enterGrade("project 1");
    project2 = enterGrade("project 2");
    project3 = enterGrade("project 3");
    quiz1 = enterGrade("quiz 1");
    quiz2 = enterGrade("quiz 2");

    double lowestProject = project1;

    if (project2 < lowestProject) {
        lowestProject = project2;
    }

    if (project3 < lowestProject) {
        lowestProject = project3;
    }

    double lowestQuiz = quiz1;

    if (quiz2 < lowestQuiz) {
        lowestQuiz = quiz2;
    }

    double finalGrade = 0.35 * final
                        + 0.25 * midterm
                        + 0.25 * (project1 + project2 + project3 - lowestProject) / 2
                        + 0.15 * (quiz1 + quiz2 - lowestQuiz);

    std::cout << std::endl << "Final grade: " << std::fixed << std::setprecision(2) << finalGrade << "% (";

    if (finalGrade >= 90) {
        std::cout << "A";
    } else if (finalGrade >= 80) {
        std::cout << "B";
    } else if (finalGrade >= 70) {
        std::cout << "C";
    } else if (finalGrade >= 60) {
        std::cout << "D";
    } else {
        std::cout << "F";
    }

    std::cout << ")" << std::endl;

    return 0;
}