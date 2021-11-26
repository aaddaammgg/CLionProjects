#include <iostream>
#include <ctime>
#include <vector>

double classAverage(std::vector<double> &grades);
double studentGrade(double score, double average);
double getPercentage(double number);
void studentAmount(double &amount);
void randomScores(std::vector<double> &grades, double amount);
void printStudent(int student, double score, double grade);
void printVector(std::vector<double> grades, double average);
void printAverage(double average);
char convertToLetterGrade(double grade);
std::string letterGradePhrase(char grade);

int main() {
    srand(time(0));

    std::vector<double> grades;
    double amount;

    studentAmount(amount);

    randomScores(grades, amount);

    double average = classAverage(grades);
    
    printVector(grades, average);
    printAverage(average);

    return 0;
}

void studentAmount(double &amount) {
    std::cout << "How many students?\n";
    std::cin >> amount;
}

void randomScores(std::vector<double> &grades, double amount) {
    for (int i = 0; i < amount; i++) {
        grades.push_back(rand() % 100);
    }
}

double classAverage(std::vector<double> &grades) {
    double totalScore = 0;

    for (int i = 0; i < grades.size(); i++) {
        totalScore += grades[i];
    }

    return totalScore / grades.size();
}

double studentGrade(double score, double average) {
    double grade = getPercentage(score / average);

    if (grade > 100) {
        grade = 100;
    }

    return grade;
}

char convertToLetterGrade(double const grade) {
    if (grade >= 90)
        return 'a';
    else if (grade >= 80)
        return 'b';
    else if (grade >= 70)
        return 'c';
    else if (grade >= 60)
        return 'd';
    else
        return 'f';
}

std::string letterGradePhrase(char const grade) {
    switch (grade) {
        case 'a':
            return "Good job";
        case 'b':
            return "Fair job";
        case 'c':
            return "Average job";
        case 'd':
            return "Not good";
        case 'f':
            return "Failure";
        default:
            return "null";
    }
}

void printStudent(int const student, double const score, double const grade) {
    char letterGrade = convertToLetterGrade(grade);

    std::cout << "student " << student << ": score: " << score << ", grade: " << grade << "%, note: " << letterGradePhrase(letterGrade) << "\n";
}

void printVector(std::vector<double> grades, double average) {
    for (int i = 0; i < grades.size(); i++) {
        double studentScore = grades[i];

        printStudent(i + 1, studentScore, studentGrade(studentScore,average));
    }
}

void printAverage(double average) {
    std::cout << "Average score: " << average << "%\n";
}

double getPercentage(double number) {
    return number * 100;
}