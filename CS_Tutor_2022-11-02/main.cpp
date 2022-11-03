#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream file("name_nums.txt");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.empty()) {
                continue;
            }

            std::string first, last;
            int counter = 0;
            double num = 0, avg = 0;

            std::stringstream lineStream(line);

            lineStream >> first >> last;

            while (lineStream >> num) {
                avg += num;
                counter++;
            }

            avg /= (double)counter;

            std::cout << first << " " << last << ": " << avg << std::endl;
        }

        file.close();
    } else {
        std::cout << "error" << std::endl;
    }

    return 0;
}
