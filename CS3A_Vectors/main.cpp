#include <iostream>
#include <vector>
#include <algorithm>

void fillVectorRandom(std::vector<int> &v, int amount);
void printVector(const std::vector<int> &v);

void fillArray(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    std::vector<int> v;



    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void fillVectorRandom(std::vector<int> &v, int amount) {
    for (int i = 0; i < amount; i++) {
        v.push_back(rand() % 100);
    }
}

void printVector(const std::vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
}