#include <iostream>

double avgDoubles(const double *arr, const int *size);

int main() {
    int numDoubles;

    std::cout << "Enter the size of the array:" << std::endl;
    std::cin >> numDoubles;

    double *arr = new double(numDoubles);

    for (int i = 0; i < numDoubles; i++) {
        std::cout << "Enter doubles (" << i << "):" << std::endl;
        std::cin >> arr[i];
    }

    double avg = avgDoubles(arr,&numDoubles);
    std::cout << "The average of the numbers is: " << avg << std::endl;

    delete arr;

    return 0;
}

double avgDoubles(const double *arr, const int *size) {
    double avg = 0;
    for (int i = 0; i < *size; i++) {
        avg += arr[i];
    }

    return avg / *size;
}