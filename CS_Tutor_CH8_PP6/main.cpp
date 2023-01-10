#include <iostream>
#include <string>

std::string replaceText(std::string text);
void findFirstDigit(const std::string& text, int startingIndex, int& start, int& end);

int main() {
    std::string s = "10 My userID is 15john17 and my 4 digit pin is 1234 which is secret.10 10";

    std::cout << s << std::endl;
    std::string replaced = replaceText(s);

    std::cout << replaced << std::endl;

    return 0;
}

std::string replaceText(std::string text) {
    int start = -1, end = -1;
    int startingIndex = 0;

    while (startingIndex < text.size()) {
        findFirstDigit(text, startingIndex, start, end);

        if (start == -1) {
            break;
        }

        for (int i = start; i < end + 1; i++) {
            text[i] = 'x';
        }

        startingIndex = end + 1;
    }

    return text;
}

void findFirstDigit(const std::string &text, int startingIndex, int &start, int &end) {
    start = -1;
    end = -1;

    for (int i = startingIndex; i < text.size(); i++) {
        if (i == startingIndex && isdigit(text[i]) && start == -1) {
            start = i;
        }

        if (isdigit(text[i]) && isspace(text[i - 1]) && start == -1) {
            start = i;
        } else if (start == -1) {
            continue;
        }

        if (i > text.size() - 1) {
            start = -1;
            end = -1;
            break;
        }

        if (isdigit(text[i]) && (isspace(text[i + 1]) || i == text.size() - 1)) {
            end = i;
            break;
        } else if (isdigit(text[i]) && isalpha(text[i + 1])) {
            start = -1;
        }
    }
}
