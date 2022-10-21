#include <ctime>
#include <iostream>

void timeDelay(int sec);

int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << " ";
        }

        std::cout << "QQQQQ";
        std::cout.flush();
        timeDelay(1);
    }
    return 0;
}

void timeDelay(int sec) {
    int currentTime = time(nullptr);

    while (time(nullptr) - currentTime <= sec){
    }
}