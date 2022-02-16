#include <iostream>

void test(int &x) {
    x = 10;
}

int main() {
    std::cout << "Enter a size: " << std::endl;
    int size;
    std::cin >> size;
    std::string arr[size];

    std::cout << "Enter a name: " << std::endl;
    std::string name;
    std::cin >> name;
    arr[0] = name;

    std::cout << arr[0] << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
