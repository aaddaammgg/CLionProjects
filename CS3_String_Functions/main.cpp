#include <iostream>
#include <string>

int main() {
    int size = 5;
    char s[] = {'H', 'e', 'l', 'l', 'o'};

    for (int i = 0; i < size; i++) {
        std::cout << "'" << s[i] << "'";

        if (!(i == size - 1)) {
            std::cout << "',";
        }
    }

    return 0;
}