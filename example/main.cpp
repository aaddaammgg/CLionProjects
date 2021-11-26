#include <iostream>
#include <iomanip>
//#include <string>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::cout << std::right << std::setw(13) << input;
}
