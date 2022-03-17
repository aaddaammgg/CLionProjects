#include <iostream>
#include <cmath>

double calculateAverage(double s1, double s2, double s3, double s4);
double calculateStandardDeviation(double s1, double s2, double s3, double s4, double average, int num);

int main() {
    double s1,s2,s3,s4;
    double avg,standDeviation;
    char repeat;
    do {
        std::cout << "Enter s1:\n";
        std::cin >> s1;

        std::cout << "Enter s2:\n";
        std::cin >> s2;

        std::cout << "Enter s3:\n";
        std::cin >> s3;

        std::cout << "Enter s4:\n";
        std::cin >> s4;

        avg = calculateAverage(s1,s2,s3,s4);
        standDeviation = calculateStandardDeviation(s1,s2,s3,s4,avg,4);

        std::cout << "Standard Deviation is: " << standDeviation << "\n";

        std::cout << "Would you like to repeat this program? Y/N\n";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

double calculateAverage(double s1, double s2,double s3, double s4) {
    return (s1 + s2 + s3 + s4) / 4;
}

double calculateStandardDeviation(double s1, double s2,double s3, double s4, double average,int num)
{
    double standDeviation;
    standDeviation = (pow((s1 - average),2) + pow((s2 - average),2)+
                      pow((s3 - average),2) + pow((s4 - average),2)) / num;
    standDeviation = sqrt(standDeviation);

    return standDeviation;
}