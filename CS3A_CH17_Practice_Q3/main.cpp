#include <iostream>
const int ARRAY_SIZE = 10;

template <class T, class T2>
void search(const T a[], T first, T last, T key, T2& found, T& location);

int main() {
    int a[ARRAY_SIZE];
    const int final_index = ARRAY_SIZE - 1;
    int key, location;
    bool found;
    std::cout << "Enter number to be located:" << std::endl;
    std::cin >> key;

    search(a, 0, final_index, key, found, location);

    if (found) {
        std::cout << key << " is in index location " << location << std::endl;
    } else {
        std::cout << key << " is not in the array." << std::endl;
    }

    return 0;
}

template <class T, class T2>
void search(const T a[], T first, T last, T key, T2& found, T& location) {
    int mid;
    if (first > last) {
        found = false;
    } else {
        mid = (first + last) / 2;

        if (key == a[mid]) {
            found = true;
            location = mid;
        } else if (key < a[mid]) {
            search(a, first, mid - 1, key, found, location);
        } else if (key > a[mid]) {
            search(a, first, mid + 1, key, found, location);
        }
    }
}