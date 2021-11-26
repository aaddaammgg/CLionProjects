#include <iostream>

bool isPalindrome(std::string word);

int main() {
    std::string word;
    char again;

    do {
        std::cout << "Enter a word:" << std::endl;
        std::cin >> word;

        if (isPalindrome(word)) {
            std::cout << word << " is a palindrome.";
        } else {
            std::cout << word << " is not a palindrome.";
        }
        std::cout << std::endl;
        std::cout << "Do you want to enter a new word? Y/N" << std::endl;
        std::cin >> again;
    } while(tolower(again) != 'n');

    return 0;
}

bool isPalindrome(std::string word) {
    char *begin = &word[0];
    char *end = &word[word.size() - 1];

    do {
        begin++;
        end--;


        if (tolower(*begin) != tolower(*end)) {
            return false;
        }
    } while (*begin == *end && (begin != end));

    return true;
}