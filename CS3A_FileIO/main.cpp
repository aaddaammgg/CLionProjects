#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void writeFile(const std::string& fileName, const std::string& content);
void readFile(const std::string& fileName);
void printVector(const std::vector<std::string> &words);

std::string lowerString(std::string word);

int main() {
    writeFile("myfile.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");

    readFile("myfile.txt");

    return 0;
}

std::string lowerString(std::string word) {

    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]);
    }

    return word;
}

void printVector(const std::vector<std::string> &words) {
    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << " ";
    }
}

void readFile(const std::string& fileName) {
    std::ifstream fin;
    fin.open(fileName);

    if (fin.fail()) {
        exit(2);
    }

    std::string word;

    std::vector<std::string> words;

    while (fin >> word) {
        words.push_back(lowerString(word));
    }

    std::sort(words.begin(), words.end());

    printVector(words);
}

void writeFile(const std::string& fileName, const std::string& content) {
    std::ofstream fout;

    fout.open(fileName);

    if (fout.fail()) {
        exit(1);
    }

    fout << content;

    fout.close();
}

