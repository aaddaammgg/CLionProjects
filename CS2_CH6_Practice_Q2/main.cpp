#include <iostream>
#include <fstream>

double getAvg(std::ifstream& file);
void outputAvg(double average);

int main() {
    const std::string fileName = "test.txt";
    std::ifstream infile;
    infile.open(fileName);

    if (infile.fail()) {
        std::cout << fileName << " file cannot be opened!\n";
        exit(1);
    }

    double average = getAvg(infile);
    outputAvg(average);

    infile.close();

    return 0;
}

double getAvg(std::ifstream& file) {
    int next, count = 0;
    double total = 0;

    while (file >> next) {
        count++;
        total += next;
    }

    return total / count;
}
void outputAvg(double average) {
    std::cout << "AVG: " << average << "\n";
}