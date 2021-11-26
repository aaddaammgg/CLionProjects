#include <iostream>

void reverseString(std::string &input);
void swapChar(char &front, char &rear);

int main() {
    std::string input = "something";
    reverseString(input);
    std::cout << input << std::endl;
    return 0;
}

void reverseString(std::string &input) {
    char *front = &input[0], *rear = &input[input.size() - 1];

    while (front < rear) {
        swapChar(*front, *rear);

        front++;
        rear--;
    }
    std::cout << input << std::endl;
}

void swapChar(char &front, char &rear) {
    char tempChar = rear;
    rear = front;
    front = tempChar;
}