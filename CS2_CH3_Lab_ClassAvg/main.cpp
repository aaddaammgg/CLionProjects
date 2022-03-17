#include <iostream>
#include <ctime>

double classAverage(const double array[], int size);
double studentGrade(double score, double average);
double getPercentage(double number);
void randomScores(double array[], int size);
void printStudent(int student, double score, double grade);
void printArray(double array[], int size, double average);
void printAverage(double average);

int main() {
    srand(time(0));

    int size = 100;
    double array[size];

    randomScores(array, size);

    double average = classAverage(array, size);

    printArray(array, size, average);
    printAverage(average);

    return 0;
}

void randomScores(double array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

double classAverage(const double array[], int size) {
    double totalScore = 0;

    for (int i = 0; i < size; i++) {
        totalScore += array[i];
    }

    return totalScore / size;
}

double studentGrade(double score, double average) {
    double grade = getPercentage(score / average);

    if (grade > 100) {
        return 100;
    }

    return grade;
}

void printStudent(int student, double score, double grade) {
    std::cout << "student " << student << ": score: " << score << ", grade: " << grade << "%\n";
}

void printArray(double array[], int size, double average) {
    for (int i = 0; i < size; i++) {
        double studentScore = array[i];

        printStudent(i + 1, studentScore, studentGrade(studentScore,average));
    }
}

void printAverage(double average) {
    std::cout << "Average score: " << average << "%\n";
}

double getPercentage(double number) {
    return number * 100;
}