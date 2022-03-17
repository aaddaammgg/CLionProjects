#include <iostream>
#include <fstream>

void welcomeBack();
void inputName();

int main() {
    welcomeBack();

    return 0;
}

void welcomeBack() {
    std::ifstream ifile;

    if (ifile.fail()) {
        exit(3);
    }

    ifile.open("name.txt");
    std::string name;
    ifile >> name;

    if (!name.empty()) {
        std::cout << "Welcome back, " << name << "!\n";
    } else {
        inputName();
    }

    ifile.close();
}

void inputName() {
    std::ofstream ofile;
    std::string name;

    ofile.open("name.txt");
    if (ofile.fail()) {
        exit(2);
    }

    std::cout << "It seems that you have not inputted a name yet. Please do so now:\n";
    std::cin >> name;

    ofile << name;

    ofile.close();

    welcomeBack();
}