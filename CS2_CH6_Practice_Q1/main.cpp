#include <iostream>
#include <fstream>

int main() {
    const std::string fileName = "test.txt";
    int number;
    int largestNumber = INT_MIN;
    int smallestNumber = INT_MAX;

    std::ifstream infile;
    infile.open(fileName);

    if (infile.fail()) {
        std::cout << fileName << " file cannot be opened!\n";
        exit(1);
    }

    while (infile >> number) {
        if (number > largestNumber) {
            largestNumber = number;
        }

        if (number < smallestNumber) {
            smallestNumber = number;
        }
    }

    std::cout << "The largest number in the file:  " << largestNumber << "\n";
    std::cout << "The smallest number in the file: " << smallestNumber << "\n";

    return 0;
}