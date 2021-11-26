#include <iostream>

template <class T, class T2>
void search(const T a[], T low_end, T high_end, T key, T2& found, T& location);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

template <class T, class T2>
void search(const T a[], T low_end, T high_end, T key, T2& found, T& location) {
    int first = low_end;
    int last = high_end;
    int mid;

    found = false;
    while ( (first <= last) && !(found) ) {
        mid = (first + last) / 2;
        if (key == a[mid]) {
            found = true;
            location = mid;
        } else if (key < a[mid]) {
            last = mid - 1;
        } else if (key > a[mid]) {
            first = mid + 1;
        }
    }
}