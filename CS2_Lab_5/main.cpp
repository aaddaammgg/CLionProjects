#include <iostream>


//a classroom of three students, the  a students are going to take a test and get a grade
//the student's grade will be curved in the following way: score/class average
//print each students score, and their grade: student 1: score: 90.7, grade: 100%

//calculate class average
double classAverage(double score1, double score2, double score3);

//calculate student grade
double studentGrade(double score, double average);

//print results
void printResults(std::string student, double score, double grade);

//get percentage
double getPercentage(double number);

int main()
{
    double student1 = 95.5, student2 = 81, student3 = 52.7;
    double average = classAverage(student1, student2, student3);
    printResults("student 1", student1, studentGrade(student1, average));
    printResults("student 2", student2, studentGrade(student2, average));
    printResults("student 3", student3, studentGrade(student3, average));
    return 0;
}

//calculate class average
double classAverage(double score1, double score2, double score3)
{
    return (score1 + score2 + score3)/3;
}

//calculate student grade
double studentGrade(double score, double average)
{
    double grade = getPercentage(score/average);
    if(grade > 100)
    {
        return 100;
    }
    return grade;
}

//print results /// student 1: score: 90.7, grade: 100%
void printResults(std::string student, double score, double grade)
{
    std::cout << student << ": score: " << score << ", grade: " << grade << "%\n";
}

//get percentage
double getPercentage(double number)
{
    return number * 100;
}